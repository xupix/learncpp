#include <iostream>

int readNumber()
{
    std::cout << "Enter an integer: ";
    int x{ };
    std::cin >> x;

    return x;
}

void writeAnswer(int answer)
{
    std::cout << "The sum is: " << answer << '\n';
}

int main()
{
    int x{ readNumber() };
    int y{ readNumber() };
    writeAnswer(x + y);

    return 0;
}

