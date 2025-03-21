#include <array>
#include <iostream>
#include <string_view>

namespace Animal {
enum Types { chicken, dog, cat, elephant, duck, snake };

struct Data {
  std::string_view name;
  int legs;
  std::string_view sound;
};
}  // namespace Animal

int main(int argc, char* argv[]) {
  std::array<Animal::Data, 6> animals{{{"chicken", 2, "cluck"},
                                       {"dog", 4, "woof"},
                                       {"cat", 4, "meow"},
                                       {"elephant", 4, "trumpet"},
                                       {"duck", 2, "quack"},
                                       {"snake", 0, "hiss"}}};

  std::string name_input;
  std::cin >> name_input;

  bool found = false;
  for (auto animal : animals) {
    if (name_input == animal.name) {
      found = true;
      std::cout << animal.name << " has " << animal.legs << " legs and says " << animal.sound
                << '\n';
    }
  }
  if (!found) {
    std::cout << "Can't find " << name_input << '\n';
  }

  std::cout << "\n\nHere are the rest \n";
  for (auto animal : animals) {
    if (name_input != animal.name) {
      std::cout << animal.name << " has " << animal.legs << " legs and says " << animal.sound
                << '\n';
    }
  }

  return 0;
}
