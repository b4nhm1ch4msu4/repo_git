#!/bin/bash

# Prompt the user for the pattern
read -p "Enter the pattern to search for (regex supported): " pattern

# Check if the pattern is empty
if [[ -z "$pattern" ]]; then
  echo "Error: No pattern entered."
  exit 1
fi

# Search for the pattern in all files in the current directory
echo "Searching for pattern '$pattern' in files..."
echo "---------------------------------------------"

# Use grep to search for the pattern in all files
# -r: recursive (search in all files in the directory and subdirectories)
# -n: show line numbers
# -H: show filenames
# --color: highlight matches
matches=$(grep -rnH --color=always "$pattern" .)

# Check if any matches were found
if [[ -z "$matches" ]]; then
  echo "No matches found for pattern '$pattern'."
else
  echo "Matches found:"
  echo "$matches"
fi
