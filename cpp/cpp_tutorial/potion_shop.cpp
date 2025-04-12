#include <array>
#include <iostream>
#include <string>
#include "random.h"

namespace Potion {
enum Type {
  healing,
  mana,
  speed,
  invisibility,
  max_potions,
};

constexpr std::array potions_cost{20, 30, 12, 50};
constexpr std::array<std::string_view, max_potions> potions_name{"healing", "mana", "speed",
                                                                 "invisibility"};
constexpr std::array types{healing, mana, speed, invisibility};

static_assert(std::size(potions_cost) == max_potions);
static_assert(std::size(potions_name) == max_potions);
static_assert(std::size(types) == max_potions);

void potion_list() {
  std::cout << "Here is our selection for today:\n";
  for (int i = 0; i < max_potions; i++) {
    std::cout << i << ") " << potions_name[i] << " costs " << potions_cost[i] << "\n";
  }
  std::cout << "\n";
}
}  // namespace Potion

class Player {
  int m_gold{};
  std::string m_name{};
  static constexpr int m_min_gold{80};
  static constexpr int m_max_gold{120};
  std::array<int, Potion::max_potions> m_inventory{0, 0, 0, 0};

 public:
  explicit Player(std::string_view name)
      : m_name(name), m_gold(Random::get(m_min_gold, m_max_gold)) {}

  int gold() const { return m_gold; }

  int inventory(Potion::Type type) const { return m_inventory[type]; }

  bool purchase(Potion::Type type) {
    if (m_gold < Potion::potions_cost[type])
      return false;
    m_gold -= Potion::potions_cost[type];
    m_inventory[type]++;
    return true;
  }
};

void IgoreLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Potion::Type whichPotion() {
  std::cout << "Which potion would you like to buy, or 'q' to quit? ";
  char input{};
  while (true) {
    std::cin >> input;
    if (!std::cin) {
      std::cin.clear();
      IgoreLine();
      continue;
    }
    if (!std::cin.eof() && std::cin.peek() != '\n') {
      std::cout << "Don't get your point! 1\n";
      IgoreLine();
      continue;
    }
    if (input == 'q') {
      return Potion::max_potions;
    }
    int num{input - '0'};
    std::cout << num << '\n';
    if (num >= 0 && num < Potion::max_potions) {
      return static_cast<Potion::Type>(num);
    }
    std::cout << "Don't get your point! 2\n";
    IgoreLine();
  }
}

void Shop(Player& player) {
  while (true) {
    Potion::potion_list();
    Potion::Type type = whichPotion();
    if (type == Potion::max_potions) {
      break;
    }
    if (player.purchase(type)) {
      std::cout << "You bought a " << Potion::potions_name[type] << ", you have " << player.gold()
                << " gold left.\n";
    } else {
      std::cout << "You don't have enough gold.\n";
    }
  }
}

void PrintInventory(const Player& player) {
  for (int i = 0; i < Potion::max_potions; i++) {
    std::cout << Potion::potions_name[i] << ": " << player.inventory(static_cast<Potion::Type>(i))
              << '\n';
  }
}

int main(int argc, char* argv[]) {
  std::cout << "Welcome to Roscoe's potion emporium!\n";
  std::cout << "Enter your name: ";
  std::string name{};
  std::getline(std::cin, name);
  Player player{name};
  std::cout << "Hello, " << name << ", you have " << player.gold() << " gold.\n\n";
  Shop(player);
  PrintInventory(player);
  std::cout << "\nThanks for shopping at Roscoe's potion emporium!\n";
  return 0;
}
