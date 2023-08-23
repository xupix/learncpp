#include <iostream>
#include "random.h"
#include "constants.h"

void startGame(int min, int max, int attempts);
void clearCinBuffer();
void handleCinBuffer();
int getGuess(int attempt, int minNumber, int maxNumber);
bool checkGuess(int guess, int num);
void printWonOrLost(bool isWon, bool isLastAttempt, int num);
bool replay();

int main()
{
  bool playAgain{ true };
  while(playAgain)
  {
    startGame(appConstants::minNumber, appConstants::maxNumber, appConstants::numOfAttempts);
    int num{ Random::get(appConstants::minNumber, appConstants::maxNumber) };
    for(int count{ 1 }; count <= appConstants::numOfAttempts; ++count)
    {
      int guess { getGuess(count, appConstants::minNumber, appConstants::maxNumber) };
      bool isLastAttempt{ count == appConstants::numOfAttempts };
      bool isGuessGood = checkGuess(guess, num);
      if(isGuessGood || isLastAttempt)
      {
        printWonOrLost(isGuessGood, isLastAttempt, num);
        break;
      }
    }
    playAgain = replay();
  }

  std::cout << "Thank you for playing.\n";
  return 0;
}

void startGame(int min, int max, int attempts)
{
  std::cout << "Let's play a game. I'm thinking of a number between " << min
    << " and " << max << ". You have " << attempts << " tries to guess what it is.\n";
}

void clearCinBuffer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// handle failed extraction, resetting cin and clearing buffer; exit on EOF
void handleCinBuffer()
{
  if(!std::cin)
  {
    if(std::cin.eof())
    {
      exit(0);
    }

    std::cin.clear();
    clearCinBuffer();
  }
  else
  {
    clearCinBuffer();
  }
}

int getGuess(int attempt, int minNumber, int maxNumber)
{
  while(true)
  {
    std::cout << "Guess #" << attempt << '\n';
    int guess{};
    std::cin >> guess;

    handleCinBuffer();

    if(guess >= minNumber && guess <= maxNumber)
    {
      return guess;
    }
  }
}

bool checkGuess(int guess, int num)
{
  if(guess > num)
    {
      std::cout << "Your guess is too high.\n";
      return false;
    }
    else if(guess < num)
    {
      std::cout << "Your guess is too low.\n";
      return false;
    }

    return true;
}

void printWonOrLost(bool isWon, bool isLastAttempt, int num)
{
  if(isWon)
  {
    std::cout << "Correct! You win!\n";
  } 
  else if(isLastAttempt)
  {
    std::cout << "Sorry, you lose. The correct number was " << num << ".\n";
  }
}

bool replay()
{
  while(true)
  {
    std::cout << "Would you like to play again (y/n)? ";
    char c{};
    std::cin >> c;

    handleCinBuffer();

    switch (c)
    {
      case 'y':
        return true;
      case 'n':
        return false;
    }
  }
}
