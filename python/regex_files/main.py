import os
import re


def extract_pattern_from_file(file_path, pattern):
    """
    Extract all occurrences of the pattern in a file.
    """
    matches = []
    try:
        with open(file_path, 'r', encoding='utf-8') as file:
            content = file.read()
            matches = re.findall(pattern, content)
    except Exception as e:
        print(f"Error reading file {file_path}: {e}")
    return matches


def extract_pattern_in_directory(directory, pattern):
    """
    Extract the pattern from all files in the directory.
    """
    all_matches = {}
    for root, _, files in os.walk(directory):
        for file_name in files:
            file_path = os.path.join(root, file_name)
            matches = extract_pattern_from_file(file_path, pattern)
            if matches:
                all_matches[file_path] = matches
    return all_matches


def main():
    # Get the pattern from user input
    pattern = input(
        "Enter the pattern to search for (regex supported): ").strip()

    # Get the current directory
    current_directory = os.getcwd()

    # Extract the pattern from all files
    results = extract_pattern_in_directory(current_directory, pattern)

    # Display the results
    if results:
        print(f"Pattern '{pattern}' found in the following files:")
        for file_path, matches in results.items():
            print(f"\nFile: {file_path}")
            print("Matches:")
            for match in matches:
                print(f"  - {match}")
    else:
        print(f"No matches found for pattern '{pattern}'.")


if __name__ == "__main__":
    main()
