import sys
import os
import argparse
from dotenv import load_dotenv
from google import genai
from google.genai import types
from prompts import system_prompt
from call_function import available_functions, call_function

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
    # user_prompt = input("User: ")
    messages = [types.Content(role="user", parts=[types.Part(text=args.user_prompt)])]
    function_results = []
    for _ in range(10):
        res = client.models.generate_content(
            model="gemini-2.5-flash",
            contents=messages,
            config=types.GenerateContentConfig(
                tools=[available_functions], system_instruction=system_prompt
            ),
        )
        if res.candidates:
            for can in res.candidates:
                if not can.content:
                    continue
                messages.append(can.content)
        # if args.verbose:
        #     print_token(res)
        # print(res.text)
        if not res.function_calls:
            print("Final response:")
            print(res.text)
            return
        for function_call in res.function_calls:
            print(f"Calling function: {function_call.name}({function_call.args})")
            function_call_result = call_function(function_call)
            if not function_call_result.parts:
                raise Exception("Error: .parts is empty")
            if function_call_result.parts[0].function_response is None:
                raise Exception("Error: Function response is None")
            if function_call_result.parts[0].function_response.response is None:
                raise Exception("Error: response is None")
            function_results.append(function_call_result.parts[0])
            if args.verbose:
                print(f"-> {function_call_result.parts[0].function_response.response}")
        messages.append(types.Content(role="user", parts=function_results))
    sys.exit("Error: Reach max loop")


if __name__ == "__main__":
    main()
