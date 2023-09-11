#include "Monster.h"

const Creature &Monster::getDefaultCreature(Type type)
{
  static const std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData{
      {{"dragon", 'D', 20, 4, 100},
       {"orc", 'o', 4, 2, 25},
       {"slime", 's', 1, 1, 10}}};

  return monsterData.at(static_cast<std::size_t>(type));
}

Monster Monster::getRandomMonster()
{
  return Monster(static_cast<Type>(Random::get(0, static_cast<int>(Monster::Type::max_types) - 1)));
}

// q3d test code
// int main()
// {
//   Monster m{Monster::Type::orc};
//   std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";

//   return 0;
// }

// q3e test code
// int main()
// {
//   // using Random.h that we've used in the past so no need for this part of the
//   // test codde as well as the random number generator they are implementing in
//   // their solution.
//   // std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
//   // std::rand();                                               // get rid of first result

//   for (int i{0}; i < 10; ++i)
//   {
//     Monster m{Monster::getRandomMonster()};
//     std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
//   }

//   return 0;
// }
