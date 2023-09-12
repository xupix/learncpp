#include <iostream>
#include <numeric>

void clearCinBuffer()
{
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// handle failed extraction, resetting cin and clearing buffer; exit on EOF
void handleCinBuffer()
{
  if (!std::cin)
  {
    if (std::cin.eof())
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
