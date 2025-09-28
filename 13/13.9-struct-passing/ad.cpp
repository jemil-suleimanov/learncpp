#include "ad.h"
#include <iostream>

struct Ad
{
    int watched { 0 };
    int percentClicked { 0 };
    int averageEarning { 0 };
};


auto calculateAdProfit(Ad& ad)
{
    return ad.watched * ad.percentClicked * ad.averageEarning;
}

void printAdd(Ad& ad) {
    std::cout << "Ads were watched: " << ad.watched << '\n';
    std::cout << "Percentage of users clicked on ad: " << ad.percentClicked << '\n';
    std::cout << "The average earnings per clicked ad: " << ad.averageEarning << '\n';

    std::cout << "Total profit of a day: " << calculateAdProfit(ad) << '\n';
}

void getAds()
{
    Ad ad { 3, 3, 3 };

    printAdd(ad);
}
