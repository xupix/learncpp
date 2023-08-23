#include <iostream>

void printByChar(const char* str)
{
  while(*str != '\0')
  {
    // i chose to print each character in its own line otherwise it's not
    // really easy to see that it works
    std::cout << *str << '\n';
    ++str;
  }
}

int main()
{
  const char* str{ "Hello world!" };
  printByChar(str);

  return 0;
}
