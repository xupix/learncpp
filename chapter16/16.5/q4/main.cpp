#include <iostream>
#include <vector>

template <typename T>
T findMax(const std::vector<T> &arr)
{
  T max{arr[static_cast<std::size_t>(0)]};
  auto length{std::ssize(arr)};
  for (int i{1}; i < length; ++i)
  {
    if (arr[static_cast<std::size_t>(i)] > max)
      max = arr[static_cast<std::size_t>(i)];
  }

  return max;
}

int main()
{
  std::vector testScore{84, 92, 76, 81, 56};
  std::cout << "The max score is: " << findMax(testScore) << '\n'; // prints 92

  return 0;
}
