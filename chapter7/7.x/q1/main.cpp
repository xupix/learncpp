#include <iostream>
#include "constants.h"

double calculateHeight(double initialHeight, int seconds)
{
    double distanceFallen { myConstants::gravity * seconds * seconds / 2 };
    double heightNow { initialHeight - distanceFallen };

    // Check whether we've gone under the ground
    // If so, set the height to ground-level
    if (heightNow < 0.0)
        return 0.0;
    else
        return heightNow;
}

void printHeight(double heightNow, int time)
{
  if(heightNow > 0)
  {
    std::cout << "At " << time << " seconds, the ball is at height: " << heightNow << '\n';
  }
  else
  {
    std::cout << "At " << time << " seconds, the ball is on the ground.\n";
  }
}

int main()
{
    std::cout << "Enter the initial height of the tower in meters: ";
    double initialHeight {};
    std::cin >> initialHeight;

    double heightNow{ initialHeight };
    int seconds{0};
    while (heightNow > 0)
    {
      heightNow = calculateHeight(initialHeight, seconds);
      printHeight(heightNow, seconds);
      ++seconds;
    }

    return 0;
}
