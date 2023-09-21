#include <iostream>
#include <vector>
#include <utility>

std::pair<int, int> getMinMaxIndices(const auto &arr)
{
  // initialize indices to first index
  int iMin{0};
  int iMax{0};

  // temp min/max values to compare results more easily. if memory is a concern
  // we can do away with these and compare to value in the appropriate index.
  auto minVal{arr[static_cast<std::size_t>(0)]};
  auto maxVal{arr[static_cast<std::size_t>(0)]};

  for (int i{0}; i < std::ssize(arr); ++i)
  {
    if (arr[static_cast<std::size_t>(i)] > maxVal)
    {
      maxVal = arr[static_cast<std::size_t>(i)];
      iMax = i;
    }
    if (arr[static_cast<std::size_t>(i)] < minVal)
    {
      minVal = arr[static_cast<std::size_t>(i)];
      iMin = i;
    }
  }

  return std::make_pair(iMin, iMax);
}

void printMinMax(const auto &arr, const auto &minMaxIndices)
{
  std::cout << "With array ( ";
  for (const auto &element : arr)
  {
    std::cout << element << ' ';
  }
  std::cout << "):\n";

  std::cout << "The min element has index "
            << minMaxIndices.first
            << " and value "
            << arr[static_cast<std::size_t>(minMaxIndices.first)]
            << '\n';
  std::cout << "The max element has index "
            << minMaxIndices.second
            << " and value "
            << arr[static_cast<std::size_t>(minMaxIndices.second)]
            << '\n';
}

int main()
{
  std::vector v1{3, 8, 2, 5, 7, 8, 3};
  std::vector v2{5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6};

  auto minMaxIndices1{getMinMaxIndices(v1)};
  auto minMaxIndices2{getMinMaxIndices(v2)};

  printMinMax(v1, minMaxIndices1);
  printMinMax(v2, minMaxIndices2);

  return 0;
}
