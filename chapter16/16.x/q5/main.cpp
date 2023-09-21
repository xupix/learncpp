#include "Random.h"
#include "Session.h"

#include <vector>
#include <iostream>
#include <string_view>

constexpr int emptyLines{25};

namespace WordList
{
  static std::vector words{"mystery", "broccoli", "account", "almost", "spaghetti", "opinion", "beautiful", "distance", "luggage"};

  std::string_view getRandomWord()
  {
    return words[static_cast<std::size_t>(Random::get(0, std::ssize(words) - 1))];
  }
}

void startGame()
{
  for (int i{0}; i < emptyLines; ++i)
    std::cout << '\n';

  std::cout << "Welcome to C++man (a variant of Hangman)\nTo win: guess the word.  To lose: run out of plusses.\n";
}

char getLetter()
{
  char ch{};

  while (!ch)
  {
    std::cout << "Enter your next letter: ";
    std::cin >> ch;

    if (!std::cin || ((ch < 'a') || (ch > 'z')))
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      std::cout << "That wasn't a valid input.  Try again.\n";
      ch = '\0';
    }
  }

  return ch;
}

void printWord(const Session &s)
{
  for (int i{0}; i < s.getWord().length(); ++i)
  {
    bool inWord{false};
    for (char ch : s.getGuessed())
    {
      if (s.getWord()[static_cast<std::size_t>(i)] == ch)
      {
        std::cout << ch;
        inWord = true;
      }
    }
    if (!inWord)
      std::cout << "_";
  }
}

void printMisses(const Session &s)
{
  std::cout << "\tWrong guesses: ";
  for (char ch : s.getMisses())
    std::cout << ch;
}

void printGameState(const Session &s)
{
  std::cout << "\nThe word: ";
  printWord(s);
  printMisses(s);

  std::cout << '\n';
}

bool checkChar(Session &s, char guess)
{
  // check it wasn't guessed already
  for (char ch : s.getGuessed())
  {
    if (ch == guess)
    {
      std::cout << "You already guessed that. Try again.\n";

      return false;
    }
  }

  for (char ch : s.getMisses())
  {
    if (ch == guess)
    {
      std::cout << "You already guessed that. Try again.\n";

      return false;
    }
  }

  // check if it's in the word
  for (char ch : s.getWord())
  {
    if (ch == guess)
    {
      std::cout << "Yes, '" << guess << "' is in the word!\n";
      s.addGuessed(guess);

      return true;
    }
  }
  std::cout << "No, '" << guess << "' is not in the word!\n";

  s.pushMiss(guess);
  return false;
}

bool isWin(const Session &s)
{
  for (char chWord : s.getWord())
  {
    bool appears{false};
    for (char chGuesses : s.getGuessed())
    {
      if (chWord == chGuesses)
      {
        appears = true;
        break;
      }
    }
    if (!appears)
      return false;
  }
  return true;
}

bool isLoss(const Session &s)
{
  for (char ch : s.getMisses())
    if (ch == '+')
      return false;

  return true;
}

int main()
{
  startGame();
  Session s{WordList::getRandomWord()};

  while (true)
  {
    printGameState(s);
    char guess{getLetter()};
    if (checkChar(s, guess))
    {
      if (isWin(s))
      {
        std::cout << "You won!  The word was: " << s.getWord() << '\n';
        return 0;
      }
    }
    else
    {

      if (isLoss(s))
      {
        std::cout << "You lost!  The word was: " << s.getWord() << '\n';
        return 0;
      }
    }
  }

  return 0;
}
