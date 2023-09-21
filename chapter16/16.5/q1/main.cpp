#include <iostream>
#include <vector>

int main()
{
  std::vector v{4, 6, 7, 3, 8, 2, 1, 9};

  // Add your code here
  for (int i{0}; i < static_cast<int>(v.size()); ++i)
  {
    std::cout << v[static_cast<std::size_t>(i)] << ' ';
  }
  std::cout << '\n';

  return 0;
}
