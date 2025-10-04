#/bin/bash

if [[ "$OSTYPE" == linux* && -f "/usr/bin/apt" ]]; then
    # Other Debian-based Linux
    echo "Detected Debian-based Linux..."
    echo "Installing required packages using apt..."
    sudo apt update
    sudo apt install -y make build-essential gcc-multilib g++-multilib
else
    echo "Error: Unsupported OS. Please install the required packages manually."
    exit 1
fi
