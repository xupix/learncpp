#include <iostream>
#include <vector>

void printStack(const auto &stack)
{
  std::cout << "\t(Stack:";

  if (stack.size() == 0)
    std::cout << " empty";

  for (const auto &element : stack)
    std::cout << ' ' << element;

  std::cout << ")\n";
}

void pushAndPrint(auto &stack, const int element)
{
  stack.emplace_back(element);
  std::cout << "Push " << element;
  printStack(stack);
}

void popAndPrint(auto &stack)
{
  stack.pop_back();
  std::cout << "Pop";
  printStack(stack);
}

int main()
{
  std::vector<int> stack{};
  stack.reserve(6); // might as well prevent reallocations :)

  printStack(stack);

  pushAndPrint(stack, 1);
  pushAndPrint(stack, 2);
  pushAndPrint(stack, 3);
  popAndPrint(stack);
  pushAndPrint(stack, 4);
  popAndPrint(stack);
  popAndPrint(stack);
  popAndPrint(stack);

  return 0;
}
