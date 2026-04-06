import os
import argparse
from dotenv import load_dotenv
from google import genai
from google.genai import types

load_dotenv()
api_key = os.environ.get("GEMINI_API_KEY")
if api_key is None:
    raise RuntimeError("Gemini api key is None!!!")

client = genai.Client(api_key=api_key)


def print_token(respond):
    # print(f"Respond: {respond.text}")
    if respond.usage_metadata is None:
        raise RuntimeError("Failed API request")
    print(f"Prompt tokens: {respond.usage_metadata.prompt_token_count}")
    print(f"Response tokens: {respond.usage_metadata.candidates_tokeuucount}")


def main():
    parser = argparse.ArgumentParser(description="Mini Claude Chatbot")
    parser.add_argument("user_prompt", type=str, help="User prompt")
    parser.add_argument("--verbose", action="store_true", help="Enable verbose output")
    args = parser.parse_args()

    messages = [types.Content(role="user", parts=[types.Part(text=args.user_prompt)])]

    res = client.models.generate_content(
        model="gemini-2.5-flash",
        contents=messages,
    )
    if (args.verbose):
        print_token(res)
    print(res.text)


if __name__ == "__main__":
    main()
