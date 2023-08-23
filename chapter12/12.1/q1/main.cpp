#include <iostream>
#include <functional>

using ArithmeticFunction = std::function<int(int, int)>;

int getInt()
{
  std::cout << "Please enter a number: ";
  int num{};
  std::cin >> num;

  return num;
}

char getOp()
{
  char op{};
  while(op != '+' && op != '-' && op != '*' && op != '/')
  {
    std::cout << "Please enter a mathematical operation (+, -, * or /): ";
    std::cin >> op;
  }

  return op;
}

int add(int x, int y)
{
  return x + y;
}

int subtract(int x, int y)
{
  return x - y;
}

int multiply(int x, int y)
{
  return x * y;
}

int divide(int x, int y)
{
  return x / y;
}

ArithmeticFunction getArithmeticFunction(char op)
{
  switch(op)
  {
    case '+': return &add;
    case '-': return &subtract;
    case '*': return &multiply;
    case '/': return &divide;
  }

  return nullptr;
}

int main()
{
  

  [[maybe_unused]] int num1{ getInt() };
  [[maybe_unused]] int num2{ getInt() };
  [[maybe_unused]] char op{ getOp() };

  ArithmeticFunction fcn{ getArithmeticFunction(op) };
  if (fcn)
  {
    std::cout << num1 << ' ' << op << ' ' << num2 << " = " << fcn(num1, num2) << '\n';
  }

  return 0;
}
