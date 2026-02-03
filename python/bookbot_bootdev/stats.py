def get_book_text(filepath: str) -> str:
    with open(filepath) as file:
        file_content = file.read()
        return file_content


def count_words(content: str) -> str:
    words = str.split(content)
    number_of_word = words.__len__()
    print(f"Found {number_of_word} total words")


def get_appear_time(content: str) -> dict:
    char_dict = {}
    word_list = str.split(content)
    for word in word_list:
        word = word.lower()
        for c in word:
            if char_dict[c] is None:
                char_dict[c] = 1
            char_dict[c] += 1
    return char_dict
