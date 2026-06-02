def get_book_text(filepath: str) -> str:
    with open(filepath) as file:
        file_content = file.read()
        return file_content


def count_words(content: str) -> str:
    words = str.split(content)
    number_of_word = words.__len__()
    print(f"Found {number_of_word} total words")


def get_appear_times(content: str) -> dict:
    char_dict = {}
    word_list = str.split(content)
    for word in word_list:
        word = word.lower()
        for c in word:
            if c not in char_dict.keys():
                char_dict[c] = 1
            else:
                char_dict[c] = char_dict[c] + 1
    return char_dict


def sort_char_dict(char_dict: dict):
    def sort_on(key):
        return char_dict[key]
    key_list = []
    for k in char_dict.keys():
        key_list.append(k)
    key_list.sort(reverse=True, key=sort_on)
    for c in key_list:
        print(f"{c}: {char_dict[c]}")
