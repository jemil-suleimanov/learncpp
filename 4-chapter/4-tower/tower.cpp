#include <iostream>

double getHeight()
{
    std::cout << "Enter the height of the tower in meters: ";
    double height{};
    std::cin >> height;

    return height;
}

double getDistance(int seconds)
{
    if (seconds == 0) {
        return 0.0;
    }
    return 9.8 * (seconds * seconds) / 2;
}

void printHeight(int sec, double height) 
{
    if (height < 0.0)
        std::cout << "At " << sec << " seconds, the ball is on the ground.\n";
    else
        std::cout << "At " << sec << " seconds, the ball is at height: " << height << " meters.\n";
}

void calculateHeightAfterDrop(double height, int seconds)
{
    double distance { getDistance(seconds) };
    printHeight(seconds, height - distance);
}

int main()
{
    double height{ getHeight() };

    calculateHeightAfterDrop(height, 0);
    calculateHeightAfterDrop(height, 1);
    calculateHeightAfterDrop(height, 2);
    calculateHeightAfterDrop(height, 3);
    calculateHeightAfterDrop(height, 4);
    calculateHeightAfterDrop(height, 5);

    return 0;
}