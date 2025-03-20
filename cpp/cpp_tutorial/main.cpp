#include <iostream>
#include <string_view>

#include "random.h"

char handle_input() {
  char input;
  bool validInput = false;
  while (!validInput) {
    std::cout << "\nEnter a letter: ";
    std::cin >> input;
    // Clear input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Check if it's a letter
    if (std::isalpha(input)) {
      validInput = true;
      input = std::tolower(input);
    } else {
      std::cout << "Invalid input !!!" << std::endl;
    }
  }
  return input;
}

bool isContainChar(char c, const std::vector<char>& vec) {
  for (char element : vec) {
    if (element == c) {
      return true;
    }
  }
  return false;
}

namespace WordList {
std::vector<std::string_view> words{"mystery",   "broccoli",  "account",
                                    "almost",    "spaghetti", "opinion",
                                    "beautiful", "distance",  "luggage"};
std::string_view get_word() {
  auto index = Random::get(0, words.size() - 1);
  return words[index];
}
}  // namespace WordList

class Session {
 public:
  Session() {
    m_gameOver = false;
    m_word = WordList::get_word();
    std::size_t len = m_word.size();
    m_answer.resize(len);
    m_guessed.resize(len);
    for (std::size_t i = 0; i < len; ++i) {
      m_answer[i] = '_';
      m_guessed[i] = '+';
    }
  }
  bool isGameOver() {
    if (isContainChar('+', m_guessed)) {
      m_gameOver = false;
    } else {
      m_gameOver = true;
      std::cout << "You lose !!! \t" << "No more guesses left !!" << std::endl;
    }
    if (!isContainChar('_', m_answer)) {
      m_gameOver = true;
      std::cout << "You win !!! " << std::endl;
    }
    return m_gameOver;
  }

  void Update(char c) {
    bool found = false;
    for (std::size_t i = 0; i < m_word.size(); ++i) {
      if (m_word[i] == c) {
        m_answer[i] = c;
        found = true;
      }
    }
    if (!found) {
      for (auto& i : m_guessed)
        if (i == '+') {
          i = c;
          break;
        }
    } else {
      std::cout << "The letter " << c << " is in the word" << std::endl;
    }
  }

  void Print_state() {
    std::cout << "Word: ";
    for (auto c : m_answer)
      std::cout << c;
    std::cout << '\t';
    std::cout << "Guessed: ";
    for (auto c : m_guessed)
      std::cout << c;
  }

 private:
  std::vector<char> m_answer;
  std::vector<char> m_guessed;
  std::string_view m_word;
  bool m_gameOver{};
};

int main(int argc, char* argv[]) {
  std::cout << "Welcome to C++man (a variant of Hangman)\n\
To win: guess the word.  To lose: run out of pluses.\n";
  std::cout << "\n\n\n";

  Session gameSession{};
  while (!gameSession.isGameOver()) {
    gameSession.Print_state();
    char guess = handle_input();
    gameSession.Update(guess);
  }
};
