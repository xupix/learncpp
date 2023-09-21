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

std::vector<int> generateArray()
{
  std::vector<int> arr{};
  std::cout << "Enter numbers to add (use -1 to stop): ";
  int input{};
  while (std::cin >> input)
  {
    if (input == -1)
      break;

    if (!std::cin) // handle bad input
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }

    arr.emplace_back(input);
  }

  return arr;
}

int main()
{
  std::vector v{generateArray()};

  auto minMaxIndices{getMinMaxIndices(v)};

  printMinMax(v, minMaxIndices);

  return 0;
}
