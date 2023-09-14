#include "Random.h"

#include <string>
#include <string_view>
#include <iostream>

class Monster
{
public:
  enum Type
  {
    dragon,
    goblin,
    ogre,
    orc,
    skeleton,
    troll,
    vampire,
    zombie,
    max_types,
  };

  Monster(Type type, std::string_view name, std::string_view roar, int hitPoints) : m_type{type}, m_name{name}, m_roar{roar}, m_hitPoints{hitPoints}
  {
  }

  std::string_view getTypeString()
  {
    switch (m_type)
    {
    case dragon:
      return "dragon";
    case goblin:
      return "goblin";
    case ogre:
      return "ogre";
    case orc:
      return "orc";
    case skeleton:
      return "skeleton";
    case troll:
      return "troll";
    case vampire:
      return "vampire";
    case zombie:
      return "zombie";
    case max_types:
    default:
      return "";
    }
  }

  void print()
  {
    std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << '\n';
  }

private:
  Type m_type{};
  std::string m_name{""};
  std::string m_roar{""};
  int m_hitPoints{};
};

namespace MonsterGenerator
{
  std::string_view getName(int num)
  {
    switch (num)
    {
    case 0:
      return "Bones";
    case 1:
      return "Cristobal";
    case 2:
      return "Danica";
    case 3:
      return "Erin";
    case 4:
      return "Frodo";
    case 5:
      return "Greta";
    default:
      return "";
    }
  }

  std::string_view getRoar(int num)
  {
    switch (num)
    {
    case 0:
      return "*rattle*";
    case 1:
      return "*skattle*";
    case 2:
      return "*trattle*";
    case 3:
      return "*ugh*";
    case 4:
      return "*vvvvv*";
    case 5:
      return "*woo*";
    default:
      return "";
    }
  }

  Monster generate()
  {
    return Monster{static_cast<Monster::Type>(Random::get(0, Monster::max_types - 1)), getName(Random::get(0, 5)), getRoar(Random::get(0, 5)), Random::get(0, 100)};
  }
}

int main()
{
  // Monster skeleton{Monster::skeleton, "Bones", "*rattle*", 4};
  // skeleton.print();
  Monster m{MonsterGenerator::generate()};
  m.print();

  return 0;
}
