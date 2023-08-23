#include <iostream>
#include <string>

double getDouble()
{
    std::cout << "Enter a double value: ";
    double d{};
    std::cin >> d;
    return d;
}

char getOp()
{
    std::cout << "Enter one of the following: +, -, *, or /: ";
    char op{};
    std::cin >> op;
    return op;
}

void printAnswer(double d1, double d2, char op, double value)
{
    std::cout << d1 << ' ' << op << ' ' << d2 << " is "  << value << '\n';
}

int main()
{
    double d1{ getDouble() };
    double d2{ getDouble() };
    char op{ getOp() };

    if(op == '+')
    {
        printAnswer(d1, d2, op, d1 + d2);
    } else if(op == '-')
    {
        printAnswer(d1, d2, op, d1 - d2);
    } else if(op == '*')
    {
        printAnswer(d1, d2, op, d1 * d2);
    } else if(op == '/')
    {
        printAnswer(d1, d2, op, d1 / d2);
    }

    return 0;
}

