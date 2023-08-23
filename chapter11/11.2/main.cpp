#include <iostream>

namespace Animals
  {
    enum Animals
    {
      chicken, 
      dog, 
      cat, 
      elephant, 
      duck, 
      snake,
      maxAnimals,
    };
  }

int main()
{
  [[maybe_unused]] double highTempOfTheDay[365]{};

  int animalLegs[Animals::maxAnimals]{ 2, 4, 4, 4, 2, 0};

  std::cout << "An elephant has " << animalLegs[Animals::elephant] << '\n';
  std::cout << "An dog has " << animalLegs[Animals::dog] << '\n';
  std::cout << "An snake has " << animalLegs[Animals::snake] << '\n';
  std::cout << "An chicken has " << animalLegs[Animals::chicken] << '\n';
}
