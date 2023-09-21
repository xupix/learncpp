#include <iostream>
#include <vector>
#include <string_view>

int main()
{
  std::vector divisors{3, 5, 7, 11, 13, 17, 19};
  std::vector<std::string_view> words{"fizz", "buzz", "pop", "bang", "jazz", "pow", "boom"};

  assert(divisors.size() == words.size() && "array sizes don't match");

  constexpr int endNum{150};
  auto length{std::ssize(divisors)};
  for (int i{1}; i < endNum; ++i)
  {
    bool isDivisible{false};
    for (int j{0}; j < length; ++j)
    {

      if (i % divisors[static_cast<std::size_t>(j)] == 0)
      {
        isDivisible = true;
        std::cout << words[static_cast<std::size_t>(j)];
      }
    }
    if (!isDivisible)
      std::cout << i;
    std::cout << '\n';
  }

  return 0;
}
