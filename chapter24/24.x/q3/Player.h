#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"
#include "Potion.h"

#include <iostream>
#include <string_view>

class Player : public Creature
{
private:
  int m_level{};

public:
  Player(std::string_view name) : Creature{name, '@', 10, 1, 0}, m_level{1}
  {
  }

  int getLevel() const { return m_level; }
  void levelUp();
  bool hasWon() const;
  void drinkPotion(Potion &potion);
};

#endif
