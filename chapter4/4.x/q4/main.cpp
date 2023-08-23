#include <iostream>

constexpr double gravity = 9.8;

double getTowerHeight()
{
    std::cout << "Enter the height of the tower in meters: ";
    double distance {};
    std::cin >> distance;

    return distance;
}

double getDistanceTravelled(int seconds)
{
    return (gravity * (seconds * seconds)) / 2.0;
}

bool isBallOnGround(double distance)
{
    return distance <= 0;
}

void printBallOnGround(int seconds)
{
    std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}

void printBallHeight(int seconds, double currentHeight)
{
    std::cout << "At " << seconds << " seconds, the ball is at height: " << currentHeight << " meters\n";
}

int main()
{
    double towerHeight{ getTowerHeight() };
    int seconds = 0;
    if (towerHeight <= 0){
        printBallOnGround(seconds);
        return 0;
    }
    printBallHeight(seconds, towerHeight);

    ++seconds; // seconds == 1
    double distanceTravelled{ getDistanceTravelled(seconds) };
    double currentHeight{ towerHeight - distanceTravelled };
    if (isBallOnGround(currentHeight))
    {
        printBallOnGround(seconds);
        return 0;
    }
    printBallHeight(seconds, currentHeight);

    ++seconds; // seconds == 2
    distanceTravelled = getDistanceTravelled(seconds);
    currentHeight = towerHeight - distanceTravelled;
    if (isBallOnGround(currentHeight))
    {
        printBallOnGround(seconds);
        return 0;
    }
    printBallHeight(seconds, currentHeight);

    ++seconds; // seconds == 3
    distanceTravelled = getDistanceTravelled(seconds);
    currentHeight = towerHeight - distanceTravelled;
    if (isBallOnGround(currentHeight))
    {
        printBallOnGround(seconds);
        return 0;
    }
    printBallHeight(seconds, currentHeight);

    ++seconds; // seconds == 4
    distanceTravelled = getDistanceTravelled(seconds);
    currentHeight = towerHeight - distanceTravelled;
    if (isBallOnGround(currentHeight))
    {
        printBallOnGround(seconds);
        return 0;
    }
    printBallHeight(seconds, currentHeight);

    ++seconds; // seconds == 5
    distanceTravelled = getDistanceTravelled(seconds);
    currentHeight = towerHeight - distanceTravelled;
    if (isBallOnGround(currentHeight))
    {
        printBallOnGround(seconds);
        return 0;
    }
    printBallHeight(seconds, currentHeight);

    return 0;
}

