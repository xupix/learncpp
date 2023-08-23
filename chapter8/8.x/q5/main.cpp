#include <iostream>

template <typename T>
T add(T x, T y)
{
  return x + y;
}

template <typename U>
U mult(U x, int y)
{
  return x * y;
}

auto sub(auto x, auto y)
{
  return x - y;
}


int main()
{
  // q5a
	std::cout << add(2, 3) << '\n';
	std::cout << add(1.2, 3.4) << '\n';

  // q5b
  std::cout << mult(2, 3) << '\n';
	std::cout << mult(1.2, 3) << '\n';

  // q5c
  std::cout << sub(3, 2) << '\n';
	std::cout << sub(3.5, 2) << '\n';
	std::cout << sub(4, 1.5) << '\n';

	return 0;
}
