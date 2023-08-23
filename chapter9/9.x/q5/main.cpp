/*
Write a function named sort2 which allows the caller to pass 2 int variables as arguments. 
When the function returns, the first argument should hold the lesser of the two values, 
and the second argument should hold the greater of the two values.
*/

#include <iostream>

void sort2(int& x, int& y)
{
  if(x <= y)
  {
    return;
  }
  int temp{ x };
  x = y;
  y = temp;
}

int main()
{
    int x { 7 };
    int y { 5 };

    sort2(x, y);
    std::cout << x << ' ' << y << '\n'; // should print 5 7

    sort2(x, y);
    std::cout << x << ' ' << y << '\n'; // should print 5 7

    sort2(y, x);
    std::cout << x << ' ' << y << '\n'; // should print 5 7

    sort2(x, y);
    std::cout << x << ' ' << y << '\n'; // should print 5 7

    return 0;
}
