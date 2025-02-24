#include <iostream>
#include <string>

struct Monster
{
  enum class Type
  {
    orc,
    dragon,
    giant_spider,
    ogre,
    slime,
  };

  Type type{};
  std::string name{};
  int health{};
};

constexpr std::string_view getMonsterTypeString(Monster::Type type)
{
  switch (type)
  {
  case Monster::Type::orc:
    return "orc";
  case Monster::Type::dragon:
    return "dragon";
  case Monster::Type::giant_spider:
    return "giant spider";
  case Monster::Type::ogre:
    return "ogre";
  case Monster::Type::slime:
    return "slime";
  }
  return "unknown";
}

void printMonster(const Monster& m)
{
  std::cout << "A " << getMonsterTypeString(m.type) << " named " << m.name
            << " has " << m.health << " health.\n";
}

int main(int argc, char* argv[])
{
  Monster ogre{Monster::Type::ogre, "Torg", 145};
  Monster slime{Monster::Type::slime, "Blurp", 23};

  printMonster(ogre);
  printMonster(slime);
  return 0;
}
