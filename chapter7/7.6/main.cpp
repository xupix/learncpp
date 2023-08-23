#include <iostream>

int calculate()
{
  std::cout << "Enter a number: ";
  int x{};
  std::cin >> x;

  std::cout << "Enter another number: ";
  int y{};
  std::cin >> y;

  std::cout << "Enter an operator +, -, *, /, or %:";
  char op{};
  std::cin >> op;

  switch(op)
  {
    case '+':
      return x + y;
    case '-':
      return x - y;
    case '*':
      return x * y;
    case '/':
      return x / y;
    case '%':
      return x % y;
    default:
      std::cout << "Invalid operator";
      return NULL;
  }
}

int main()
{

  std::cout << calculate();


  return 0;
}
