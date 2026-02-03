from stats import get_book_text, count_words, get_appear_time


def main():
    book_filepath = "./books/frankenstein.txt"
    book_content = get_book_text(book_filepath)
    char_dict = get_appear_time(book_content)
    # count_words(book_content)
    print(char_dict)


if __name__ == "__main__":
    main()
