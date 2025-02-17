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
}

using Hell::troll;

int main(int argc, char* argv[])
{
  Hell::MonsterType m{troll};
  return 0;
}
