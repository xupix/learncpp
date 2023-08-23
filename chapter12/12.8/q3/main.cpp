#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>
#include <cmath>
#include <chrono>

namespace consts
{
  constexpr int minRand{ 2 };
  constexpr int maxRand{ 4 };
  constexpr int upToVariance{ 4 };
};

std::vector<int> generateVector(const int startNum, int count, int randomMultiplier)
{
  std::vector<int> v(static_cast<std::vector<int>::size_type>(count));

  int i{ startNum };

  for (auto& num : v)
  {
    num = (i * i * randomMultiplier);
    ++i;
  }

  return v;
}

std::vector<int> getNumbers(int multiplier)
{
  std::cout << "Start where? ";
  int startNum{ };
  std::cin >> startNum;

  std::cout << "How many? ";
  int count{ };
  std::cin >> count;

  return generateVector(startNum, count, multiplier);
}

int getRandomMultiplier(int min, int max)
{
  static std::mt19937 mt { static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count()) };
  return std::uniform_int_distribution { min, max }(mt);
}

int getGuess()
{
  int guess{ };

  std::cout << "> ";
  std::cin >> guess;

  return guess;
}

bool checkGuessAndRemove(std::vector<int>& v, int guess)
{
  auto found{ std::find(v.begin(), v.end(), guess) };
  if(found != v.end())
  {
    v.erase(found);
    return true;
  }
  return false;
}

int findMinClosestNum(std::vector<int>& v, const int guess)
{
  return *std::min_element(v.begin(), v.end(), 
                   [=](const int a, const int b){
                    return (std::abs(a - guess) < std::abs(b - guess));
                   });
}

void printSuccess(std::vector<int>::size_type length)
{
  std::cout << "Nice! ";
  if (length > 0)
  {
    std::cout << length << " number(s) left.\n";
  }
  else
  {
    std::cout << "You found all numbers, good job!\n";
  }
}

void printFailure(std::vector<int>& v, int guess)
{
  int minClosestNum{ findMinClosestNum(v, guess) };

  if (std::abs(guess - minClosestNum) > consts::upToVariance)
  {
    std::cout << guess << " is wrong!\n";
  }
  else
  {
    std::cout << guess << " is wrong! Try " << minClosestNum << " next time.\n";
  }
}

bool round(std::vector<int>& v)
{
  int guess{ getGuess() };

  if(checkGuessAndRemove(v, guess))
  {
    printSuccess(v.size());
    if(v.size() == 0) return false;
    return true;
  }
  printFailure(v, guess);
  return false;
}

int main()
{
  int randMultiplier{ getRandomMultiplier(consts::minRand, consts::maxRand) };
  std::vector<int> v { getNumbers(randMultiplier) };

  std::cout << "I generated " << v.size() << 
               " square numbers. Do you know what each number is after multiplying it by " << 
               randMultiplier << "?\n";

  while(round(v))
  {}

  return 0;
}
