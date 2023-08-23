#include <string_view>
#include <iostream>

enum class MonsterType
{
  ogre,
  dragon, 
  orc,
  giantSpider,
  slime,
};

struct Monster
{
  MonsterType type{};
  std::string_view name{};
  int health{};
};

constexpr std::string_view getMonsterType(const MonsterType& monsterType)
{
  using enum MonsterType;

  switch(monsterType)
  {
    case ogre: return "Ogre";
    case dragon: return "Dragon";
    case orc: return "Orc";
    case giantSpider: return "Giant Spider";
    case slime: return "Slime";
  }

  return "No such monster type";

}

void printMonster(const Monster& monster)
{
  std::cout << "This " << getMonsterType(monster.type) << " is named " <<
    monster.name << " and has " << monster.health << " health.\n";
}

int main()
{
  Monster ogre{ MonsterType::ogre, "Torg", 145 };
  Monster slime{ MonsterType::slime, "Blurp", 23 };

  printMonster(ogre);
  printMonster(slime);

  return 0;
}
