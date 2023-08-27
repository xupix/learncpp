#include "random.h"
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

    max_monster_types,
  };

private:
  Type m_type{};
  std::string m_name{};
  std::string m_roar{};
  int m_hitPoints{};

public:
  Monster(Type type, std::string name, std::string roar, int hitPoints)
      : m_type{type}, m_name{name}, m_roar{roar}, m_hitPoints{hitPoints}
  {
  }

  std::string_view getTypeString() const
  {
    switch (m_type)
    {
    case Type::dragon:
      return "dragon";
    case Type::goblin:
      return "goblin";
    case Type::ogre:
      return "ogre";
    case Type::orc:
      return "orc";
    case Type::skeleton:
      return "skeleton";
    case Type::troll:
      return "troll";
    case Type::vampire:
      return "vampire";
    case Type::zombie:
      return "zombie";
    default:
      return "no such monster";
    }
  }

  void print() const
  {
    std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << '\n';
  }
};

namespace MonsterGenerator
{
  Monster generate()
  {
    const int numMonsters{Monster::Type::max_monster_types - 1};
    static constexpr std::array s_names{"philip", "benzoi", "melcor", "rubix", "elro", "bob"};
    static constexpr std::array s_roars{"meow", "roar", "pspspspsps", "woof", "hoot", "ahhh"};

    return Monster{Monster::Type{
                       static_cast<Monster::Type>(Random::get(0, numMonsters))},
                   s_names[Random::get<std::size_t>(0, s_names.size() - 1)], s_roars[Random::get<std::size_t>(0, s_roars.size() - 1)], Random::get(1, 100)};
  }
}

int main()
{
  Monster skeleton{Monster::skeleton, "Bones", "*rattle*", 4};
  skeleton.print();

  Monster m{MonsterGenerator::generate()};
  m.print();

  return 0;
}
