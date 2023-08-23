#include <iostream>

void bubbleSort(int array[], int arraySize);

int main()
{
  int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
  int arraySize{ static_cast<int>(std::size(array)) };

  bubbleSort(array, arraySize);

  // print array
  for (int i{ 0 }; i < arraySize; ++i)
  {
		std::cout << array[i] << ' ';
  }
	std::cout << '\n';

  int array1[]{ 1, 2, 4, 3, 5, 6, 7, 8, 9 };
  int array1Size{ static_cast<int>(std::size(array)) };

  bubbleSort(array1, array1Size);

  // print array
  for (int i{ 0 }; i < array1Size; ++i)
  {
		std::cout << array1[i] << ' ';
  }
	std::cout << '\n';

  return 0;
}


void bubbleSort(int array[], int arraySize)
{
    // C) Repeat the first two steps again until the array is sorted.
  for(int i { 0 }; i < arraySize - 1; ++i )
  {
    bool isSwapped{ false };
  // B) Now do the same for elements 1 and 2, and every subsequent pair of elements until you hit the end of the array. At this point, the last element in the array will be sorted.
    for(int j { 0 }; j < arraySize - i - 1; ++j)
    {
      // A) Compare array element 0 with array element 1. If element 0 is larger, swap it with element 1.
      if (array[j] > array[j + 1])
      {
        std::swap(array[j], array[j + 1]);
        isSwapped = true;
      }
    }

    if(!isSwapped)
    {
      std::cout << "Early termination on iteration " << i << '\n';
      return;
    }
  }
}
