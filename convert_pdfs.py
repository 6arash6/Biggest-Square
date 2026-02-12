#!/usr/bin/env python3
"""
Convert PDFs in C00/ to C13/ to Markdown using Docling.
Run: python convert_pdfs.py
"""

import os
from docling.document_converter import DocumentConverter

def convert_pdfs_to_md():
    converter = DocumentConverter()

    for i in range(14):  # 00 to 13
        pdf_path = f"C{i:02d}/c{i:02d}.pdf"
        md_path = f"C{i:02d}/c{i:02d}.md"

        if os.path.exists(pdf_path):
            print(f"Converting {pdf_path} to {md_path}...")
            try:
                result = converter.convert(pdf_path)
                markdown = result.document.export_to_markdown()

                with open(md_path, 'w', encoding='utf-8') as f:
                    f.write(markdown)

                print(f"✅ Saved {md_path}")
            except Exception as e:
                print(f"❌ Failed to convert {pdf_path}: {e}")
        else:
            print(f"⚠️ PDF not found: {pdf_path}")

if __name__ == "__main__":
    convert_pdfs_to_md()