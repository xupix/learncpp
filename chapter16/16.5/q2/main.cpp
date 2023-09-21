#include <iostream>
#include <vector>

// Implement printArray() here
template <typename T>
void printArray(const std::vector<T> &v)
{
  for (int i{0}; i < static_cast<int>(v.size()); ++i)
  {
    std::cout << v[static_cast<std::size_t>(i)] << ' ';
  }
  std::cout << '\n';
}

int main()
{
  std::vector arr{4, 6, 7, 3, 8, 2, 1, 9};

  printArray(arr); // use function template to print array

  return 0;
}
