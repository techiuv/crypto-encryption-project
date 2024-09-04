#!/bin/bash

UPLOAD_DIR="upload"
ENCRYPTED_DIR="encrypted"
ENCRYPTION_KEY="my_secret_key"  # Use a secure and dynamic key

# Function to log errors and exit
log_error() {
    echo "Error: $1" >&2
    exit 1
}

# Ensure the upload directory exists and contains files
[ -d "$UPLOAD_DIR" ] || log_error "Upload directory '$UPLOAD_DIR' does not exist."
[ "$(ls -A "$UPLOAD_DIR")" ] || log_error "No files found in the upload directory."

# Ensure the encrypted directory exists and is writable
mkdir -p "$ENCRYPTED_DIR" || log_error "Failed to create directory '$ENCRYPTED_DIR'."
[ -w "$ENCRYPTED_DIR" ] || log_error "Encrypted directory '$ENCRYPTED_DIR' is not writable."

# Iterate and encrypt files
for file in "$UPLOAD_DIR"/*; do
    [ -f "$file" ] || continue  # Skip non-regular files
    [ -r "$file" ] || { echo "Warning: Cannot read '$file'. Skipping..." >&2; continue; }

    encrypted_file="$ENCRYPTED_DIR/$(basename "$file").enc"
    ./encrypt "$file" "$encrypted_file" "$ENCRYPTION_KEY" || log_error "Encryption failed for '$file'."

    echo "Encrypted: $file -> $encrypted_file"
done
