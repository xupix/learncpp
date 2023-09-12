#include "Player.h"

#include <iostream>

void Player::levelUp()
{
  ++m_level;
  ++m_damage;
}

bool Player::hasWon() const { return m_level >= 20; }

void Player::drinkPotion(Potion &potion)
{
  std::cout << "You drank a " << potion.getName() << ".\n";
  switch (potion.getType())
  {
  case Potion::Type::strength:
    ++m_damage;
    break;
  case Potion::Type::poison:
    --m_health;
    break;
  case Potion::Type::health:
    (potion.getSize() == Potion::Size::large) ? m_health += 5 : m_health += 2;
    break;
  case Potion::Type::max_types:
  default:
    std::cout << "No such potion.\n";
    break;
  }
}

// Player test code
// int main()
// {
//   std::cout << "Enter your name: ";
//   std::string name{};
//   std::cin >> name;
//   Player p{name};

//   std::cout << "Welcome, " << p.getName() << ".\n";
//   std::cout << "You have " << p.getHealth() << " health and are carrying " << p.getGold() << " gold.\n";

//   return 0;
// }
