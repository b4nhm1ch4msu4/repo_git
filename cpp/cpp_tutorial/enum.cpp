#include <iostream>
#include <ostream>

enum WeaponType
{
  sword,
  axe,
  mace,
  staff,
};

namespace Hell
{
enum MonsterType
{
  orc,
  goblin,
  troll,
  ogre,
  skeleton,
};
} // namespace Hell

std::ostream& operator<<(std::ostream& out, Hell::MonsterType type)
{
  switch (type)
  {
  case Hell::orc:
    return out << "orc";
  case Hell::goblin:
    return out << "goblin";
  case Hell::troll:
    return out << "troll";
  case Hell::ogre:
    return out << "ogre";
  case Hell::skeleton:
    return out << "skeleton";
  default:
    return out << "unknown";
  }
}

std::istream& operator>>(std::istream& in, Hell::MonsterType& type)
{
  std::string s;
  in >> s;
  if (s == "orc")
  {
    type = Hell::orc;
  }
  else if (s == "goblin")
  {
    type = Hell::goblin;
  }
  else if (s == "troll")
  {
    type = Hell::troll;
  }
  else if (s == "ogre")
  {
    type = Hell::ogre;
  }
  else if (s == "skeleton")
  {
    type = Hell::skeleton;
  }
  else
  {
    in.setstate(std::ios_base::failbit);
  }
  return in;
}
int main(int argc, char* argv[])
{
  /*std::cout << Hell::orc << "\n";*/
  /*Hell::MonsterType my_monster;*/
  /*std::cin >> my_monster;*/
  /*std::cout << "Your monster is a " << my_monster;*/
  if (Hell::orc == WeaponType::sword)
    std::cout << "true\n";
  else
    std::cout << "false\n";

  return 0;
}
