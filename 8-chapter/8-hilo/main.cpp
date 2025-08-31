// 1) pick random integer between 1 and 100 
// user tries to guess number
// if lower - low, higher - high
// if guess - won
// if no guesses left - game over and tell number
// after all ask user if they want to play y/n till correct answer

/*
Update your previous solution to
- handle invalid guesses (e.g. ‘x’) +
- out of bounds guesses (e.g. 0 or 101) +
- or valid guesses that have extraneous characters (e.g. 43x).
- Also handle the user entering extra characters when the game asks them whether they want to play again.

Hint: Write a separate function to handle the user inputting their guess (along with the associated error handling).
*/
#include "Random.h"
#include <iostream>

bool hasUnextractedInput()
{
    return !std::cin.eof() && std::cin.peek() != '\n';
}

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getRandomNumber(int min, int max)
{
    std::uniform_int_distribution<> die6{min, max};
    return die6(Random::mt);
}

int getNumber(int guessCount, int min, int max)
{
    while (true) {
        std::cout << "Guess #" << guessCount << ": ";
        int guess {};
        std::cin >> guess;
        bool success { std::cin };
        std::cin.clear();
        ignoreLine();
        if (success && (guess < min || guess > max)) {
            std::cout << "Number is out of range " << min << " and " << max << '\n';
            success = false;
        }
        if (success) {
            return guess;
        }
    }
    
}

void playGame(int minValue, int maxValue, int attempts) {
    int randomNumber { getRandomNumber(minValue, maxValue) };
    int guessCount {0};

    std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is. \n";

    while (guessCount < attempts) {
        ++guessCount;
        int guess { getNumber(guessCount, minValue, maxValue) };
        if (guess < randomNumber) {
            std::cout << "Your guess is too low.\n";
            continue;
        }
        if (guess > randomNumber) {
            std::cout << "Your guess is too high.\n";
            continue;
        }
        if (guess == randomNumber) {
            std:: cout << "Correct! You win! \n";
            return;
        }
    }


    if (guessCount == attempts) {
        std:: cout << "Sorry, you lose. The correct number was " << randomNumber << '\n';
    }
}

bool playAgain() {
    char playAgain {};
    std::cout << "Would you like to play again (y/n)?";
    std::cin >> playAgain;
    bool isValid { std::cin };
    std::cin.clear();
    ignoreLine();
    if (!isValid) {
        return true;
    }

    if (playAgain == 'y') {
        return true;
    }
    if (playAgain == 'n') {
        return false;
    }
    return false;
}

int main()
{

    do {
        playGame(1, 100, 7);
    }
    while (playAgain());
    
    std::cout << "Thank you for playing.\n";
    
    return 0;
}
