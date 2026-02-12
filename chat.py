import os
import json
import requests
from llama_cpp import Llama

# --- CONFIGURATION ---
MODEL_PATH = "./models/deepseek-coder-6.7b-instruct.Q4_K_M.gguf"
MD_DIR = "./"  # Directory containing C00/ to C13/ with .md files
THREADS = 16
CONTEXT_WINDOW = 8192

# --- TOOLS ---
def web_search(query, max_results=3):
    api_key = os.environ.get("TAVILY_API_KEY")
    if not api_key:
        return "Error: TAVILY_API_KEY environment variable not set."
    
    try:
        r = requests.post(
            "https://api.tavily.com/search",
            json={
                "api_key": api_key,
                "query": query,
                "max_results": max_results,
                "search_depth": "basic"
            },
            timeout=15
        )
        r.raise_for_status()
        results = r.json().get("results", [])
        return "\n".join([f"Source: {res['url']}\nContent: {res['content']}" for res in results])
    except Exception as e:
        return f"Search failed: {str(e)}"

def get_md_context(query, md_files):
    # Simple keyword matching for RAG with Markdown files
    keywords = query.lower().split()
    matches = []
    for name, content in md_files.items():
        if any(kw in content.lower() for kw in keywords):
            matches.append(f"From {name}:\n{content}")
    return "\n---\n".join(matches[:3])

# --- INITIALIZATION ---
print(f"🚀 Loading DeepSeek Coder on {THREADS} CPUs...")
llm = Llama(model_path=MODEL_PATH, n_threads=THREADS, n_ctx=CONTEXT_WINDOW)

md_files = {}
for i in range(14):
    md_path = f"C{i:02d}/c{i:02d}.md"
    if os.path.exists(md_path):
        with open(md_path, 'r', encoding='utf-8') as f:
            md_files[f"C{i:02d}"] = f.read()
    else:
        print(f"⚠️ MD file not found: {md_path}")

if not md_files:
    print("⚠️ No MD files found. RAG disabled.")
else:
    print(f"📄 Loaded {len(md_files)} MD files for context.")

history = [{"role": "system", "content": "You are a helpful AI coding assistant with access to local docs and the web. Cite your sources."}]

# --- MAIN LOOP ---
print("\nReady! Use '/web <query>' for internet search or just type to chat with your PDFs.")

while True:
    user_input = input("\n👤 You: ").strip()
    if user_input.lower() in ['exit', 'quit']: break
    if not user_input: continue

    # Determine Mode
    if user_input.startswith("/web "):
        search_query = user_input[5:]
        print(f"🔍 Searching the web for: {search_query}...")
        context = web_search(search_query)
        prompt = f"WEB SEARCH RESULTS:\n{context}\n\nUSER QUESTION: {search_query}"
    else:
        print("📄 Checking local MD files...")
        context = get_md_context(user_input, md_files)
        prompt = f"LOCAL MD CONTEXT:\n{context}\n\nUSER QUESTION: {user_input}"

    history.append({"role": "user", "content": prompt})

    print("🤖 AI: ", end="", flush=True)
    full_response = ""
    
    # Generate the full response at once (faster perceived output)
    response = llm.create_chat_completion(messages=history, stream=False)
    full_response = response['choices'][0]['message']['content']
    print(full_response)

    history.append({"role": "assistant", "content": full_response})
    
    # Keep history manageable (last 10 messages)
    if len(history) > 11:
        history = [history[0]] + history[-10:]