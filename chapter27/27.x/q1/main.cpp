#include <exception>
#include <stdexcept>
#include <iostream>

class Fraction
{
public:
  Fraction(int numerator = 0, int denominator = 1) : m_numerator{numerator}, m_denominator{denominator}
  {
    if (m_denominator == 0)
      throw std::runtime_error("invalid denominator: 0");
  }

  friend std::ostream &operator<<(std::ostream &out, const Fraction &frac);

private:
  int m_numerator{0};
  int m_denominator{1};
};

std::ostream &operator<<(std::ostream &out, const Fraction &frac)
{
  out << frac.m_numerator << '/' << frac.m_denominator;

  return out;
}

int main()
{
  std::cout << "Enter the numerator: ";
  int numerator{};
  std::cin >> numerator;

  std::cout << "Enter the denominator: ";
  int denominator{};
  std::cin >> denominator;

  try
  {
    Fraction frac{numerator, denominator};
    std::cout << "Fraction: " << frac << '\n';
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }

  return 0;
}
