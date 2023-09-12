#include "Random.h"
#include "Player.h"
#include "Monster.h"
#include "ClearInput.h"

#include <iostream>

constexpr int POTION_FREQUENCY_PERCENT = 30;

bool fightMonster(Player &p, Monster &m);
void attackMonster(Player &p, Monster &m);
void attackPlayer(Player &p, Monster &m);
void deadMonster(Player &p, Monster &m);
void deadPlayer(const Player &p);
bool foundPotion();
void handlePotion(Player &p);

int main()
{
  std::cout << "Enter your name: ";
  std::string name{};
  std::cin >> name;
  Player p{name};

  std::cout << "Welcome, " << p.getName() << ".\n";

  while (!p.hasWon())
  {
    Monster m{Monster::getRandomMonster()};
    std::cout << "You have encountered a " << m.getName() << " (" << m.getSymbol() << ").\n";

    std::cout << std::boolalpha;

    bool didEnd{false};
    while (!m.isDead() && !didEnd)
    {
      didEnd = fightMonster(p, m);
      if (p.isDead())
        return 0;
    }
  }

  std::cout << "You won! You reached level " << p.getLevel() << " with " << p.getGold() << " gold.\n";
  return 0;
}

bool fightMonster(Player &p, Monster &m)
{
  std::cout << "(R)un or (F)ight: ";
  char action{};
  std::cin >> action;
  ClearInput::handleCinBuffer();

  if (action == 'r' || action == 'R')
  {
    bool didRun{static_cast<bool>(Random::get(0, 1))};
    if (didRun)
    {
      std::cout << "You successfully fled.\n";
      return true;
    }

    std::cout << "You failed to flee.\n";
    attackPlayer(p, m);
    if (p.isDead())
    {
      deadPlayer(p);
      return true;
    }
  }
  else if (action == 'f' || action == 'F')
  {
    attackMonster(p, m);
    if (m.isDead())
    {
      deadMonster(p, m);
      if (foundPotion())
      {
        handlePotion(p);
        if (p.isDead())
          deadPlayer(p);
      }
      return true;
    }
    else if (!p.hasWon())
    {
      attackPlayer(p, m);
      if (p.isDead())
      {
        deadPlayer(p);
        return true;
      }
    }
  }
  return false;
}

void attackMonster(Player &p, Monster &m)
{
  std::cout << "You hit the " << m.getName() << " for " << p.getDamage() << " damage.\n";
  m.reduceHealth(p.getDamage());
}

void attackPlayer(Player &p, Monster &m)
{
  std::cout << "The " << m.getName() << " hit you for " << m.getDamage() << " damage.\n";
  p.reduceHealth(m.getDamage());
}

void deadMonster(Player &p, Monster &m)
{
  std::cout << "You killed the " << m.getName() << ".\n";
  p.levelUp();
  std::cout << "You are now level " << p.getLevel() << ".\n";
  p.addGold(m.getGold());
  std::cout << "You found " << m.getGold() << " gold.\n";
}

void deadPlayer(const Player &p)
{
  std::cout << "You died at level " << p.getLevel() << " and with " << p.getGold() << " gold.\n";
  if (p.getGold() > 0) // output only makes sense if player has gold.
    std::cout << "Too bad you can’t take it with you!\n";
}

bool foundPotion()
{
  int isFound{Random::get(1, 100)};

  if (isFound <= POTION_FREQUENCY_PERCENT)
    return true;
  return false;
}

void handlePotion(Player &p)
{
  char response{};
  while (response != 'y' && response != 'Y' && response != 'n' && response != 'N')
  {
    std::cout << "You found a mythical potion! Do you want to drink it? [y/n]: ";
    std::cin >> response;
    ClearInput::handleCinBuffer();
  }
  if (response == 'y' || response == 'Y')
  {
    Potion potion{};
    p.drinkPotion(potion);
  }
}
