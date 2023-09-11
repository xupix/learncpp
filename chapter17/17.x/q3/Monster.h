#ifndef MONSTER_H
#define MONSTER_H

#include "Creature.h"
#include "Random.h"

#include <iostream>
#include <string>

class Monster : public Creature
{
public:
  enum class Type
  {
    dragon,
    orc,
    slime,
    max_types,
  };

  Monster(Type type) : Creature{getDefaultCreature(type)}
  {
  }

  static Monster getRandomMonster();

private:
  static const Creature &getDefaultCreature(Type type);
};

#endif
