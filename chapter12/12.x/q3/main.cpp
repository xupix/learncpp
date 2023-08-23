#include <iostream>
#include <iterator>
#include <numeric>

// array is the array to search over.
// target is the value we're trying to determine exists or not.
// min is the index of the lower bounds of the array we're searching.
// max is the index of the upper bounds of the array we're searching.
// binarySearch() should return the index of the target element if the target is found, -1 otherwise
int binarySearchIterative(const int* array, int target, int min, int max)
{
  assert(array);

  while (target <= array[max] && target >= array[min])
  {
    int midPoint{ std::midpoint(min, max) };
    if (target == array[midPoint])
    {
      return midPoint;
    }
    else if (target > array[midPoint])
    {
      min = midPoint + 1;
    }
    else if (target < array[midPoint])
    {
      max = midPoint - 1;
    }
  }
  return -1;
}

int binarySearchRecursive(const int* array, int target, int min, int max)
{
  assert(array);

  int midPoint{ std::midpoint(min, max) };

  if (target > array[max] || target < array[min])
  {
    return -1;
  }
  else if (target == array[midPoint])
  {
    return midPoint;
  }
  else if (target > array[midPoint])
  {
    return binarySearchRecursive(array, target, midPoint + 1, max);
  }
  else if (target < array[midPoint])
  {
    return binarySearchRecursive(array, target, min, midPoint - 1);
  }
  return -1; // to avoid a warning for potentially not returning
}

int main()
{
    constexpr int array[]{ 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };

    // We're going to test a bunch of values to see if they produce the expected results
    constexpr int numTestValues{ 9 };
    // Here are the test values
    constexpr int testValues[numTestValues]{ 0, 3, 12, 13, 22, 26, 43, 44, 49 };
    // And here are the expected results for each value
    int expectedValues[numTestValues]{ -1, 0, 3, -1, -1, 8, -1, 13, -1 };

    // Loop through all of the test values for iterative solution
    std::cout << "\nIterative solution: \n";
    for (int count{ 0 }; count < numTestValues; ++count)
    {
        // See if our test value is in the array
        int index{ binarySearchIterative(array, testValues[count], 0, static_cast<int>(std::size(array)) - 1) };
        // If it matches our expected value, then great!
        if (index == expectedValues[count])
             std::cout << "test value " << testValues[count] << " passed!\n";
        else // otherwise, our binarySearch() function must be broken
             std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
    }

    // Loop through all of the test values for recursive solution
    std::cout << "\nRecursive solution: \n";
    for (int count{ 0 }; count < numTestValues; ++count)
    {
        // See if our test value is in the array
        int index{ binarySearchRecursive(array, testValues[count], 0, static_cast<int>(std::size(array)) - 1) };
        // If it matches our expected value, then great!
        if (index == expectedValues[count])
             std::cout << "test value " << testValues[count] << " passed!\n";
        else // otherwise, our binarySearch() function must be broken
             std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
    }

    return 0;
}
