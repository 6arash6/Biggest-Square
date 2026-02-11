# Debian/Ubuntu-based devcontainer for campus repo
FROM mcr.microsoft.com/vscode/devcontainers/ubuntu:22.04

# Avoid prompts during package installs
ENV DEBIAN_FRONTEND=noninteractive

# Install system packages needed for C and Python development
RUN apt-get update \
 && apt-get install -y --no-install-recommends \
    build-essential \
    gcc \
    g++ \
    make \
    cmake \
    python3 \
    python3-venv \
    python3-pip \
    git \
    curl \
    ca-certificates \
    libssl-dev \
    libffi-dev \
    pkg-config \
    openssh-client \
 && rm -rf /var/lib/apt/lists/*

# Ensure pip tooling is up-to-date and install UV (fast package manager)
RUN python3 -m pip install --upgrade pip setuptools wheel uv

# Use bash as default shell for terminal
SHELL ["/bin/bash", "-lc"]

# Workdir used by VS Code. The repo will be mounted here by the remote container.
WORKDIR /workspace
