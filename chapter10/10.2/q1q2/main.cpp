namespace MonsterType
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

int main()
{
  [[maybe_unused]] MonsterType::MonsterType troll{ MonsterType::troll};

  return 0;
}
