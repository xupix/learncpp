#include <iostream>

struct Fraction
{
  int numerator{};
  int denominator{ 1 };
};

void getFractionFromUser(Fraction& fraction);
Fraction multiplyFractions(const Fraction& fraction1, const Fraction& fraction2);
void printFraction(const Fraction& fraction);

int main()
{
  Fraction fraction1{};
  getFractionFromUser(fraction1);

  Fraction fraction2{};
  getFractionFromUser(fraction2);

  Fraction multipliedFraction{ multiplyFractions(fraction1, fraction2)};

  printFraction(multipliedFraction);

  return 0;
}

void getFractionFromUser(Fraction& fraction)
{
  std::cout << "Enter a value for the numerator: ";
  // int numerator{};
  std::cin >> fraction.numerator;

  std::cout << "Enter a value for the denominator: ";
  // int denominator{};
  std::cin >> fraction.denominator;  
  std::cout << '\n';
}

Fraction multiplyFractions(const Fraction& fraction1, const Fraction& fraction2)
{
  return Fraction { fraction1.numerator * 
    fraction2.numerator, fraction1.denominator * fraction2.denominator };
  // return frac;
}

void printFraction(const Fraction& fraction)
{
  std::cout << "Your fractions multiplied together: " << fraction.numerator
    << '/' << fraction.denominator << '\n';
}
