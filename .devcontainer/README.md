This devcontainer is an Ubuntu 22.04 based development container configured for the `campus` repository.

What it provides:
- System packages for C/C++ development: build-essential, gcc, g++, make, cmake
- Python 3 + venv and pip for Python helper scripts and tests
- Installs Python packages from `requirements.txt` in a `.venv` created during `postCreateCommand`
- Forwards port 8501 for Streamlit apps (e.g. Rush01)

Usage:
1. Open this repository with VS Code and the Remote - Containers / Codespaces feature.
2. Choose "Reopen in Container". The container image will be built and the post-create step will set up `.venv` and install `requirements.txt`.

Notes:
- The `postCreateCommand` creates a local `.venv` and installs `requirements.txt` into it. Activate it with `source .venv/bin/activate` when you open a terminal.
- If you need the `abacusai` package, add it to `requirements.txt` or install it manually inside the container (`python -m pip install abacusai`).
