#!/usr/bin/env bash
set -o errexit
set -o errtrace
set -o nounset
set -o pipefail

# Default to b4nhm1ch4msu4
target_user="${1:-b4nhm1ch4msu4}"

# Check if jq is installed
if ! [ -x "$(command -v jq)" ]; then
  echo "jq is not installed. Please install jq and try again." >&2
  exit 1
fi

# Get user info
github_api="https://api.github.com/users/"
tmp_user_dump="/tmp/ghuserdump_$target_user.json"

result=$(curl -s "$github_api$target_user")
echo "$result" >"$tmp_user_dump"

name=$(jq -r '.name' "$tmp_user_dump" -r)
create_at=$(jq -r '.created_at' "$tmp_user_dump" -r)
join_year=$(echo "$create_at" | cut -f1 -d"-")
echo "$name" joined Github in "$join_year"
