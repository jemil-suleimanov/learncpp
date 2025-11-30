#include "Random.h"
#include <iostream>
#include <vector>
#include <cctype>
#include <string_view>
#include <string>

void printRules()
{
    std::cout << "Welcome to C++man (a variant of Hangman)\n";
    std::cout << "To win: guess the word. To lose run out of pluses.c\n";
}

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool clearFailedExtraction()
{
    // Check for failed extraction
    if (!std::cin) // If the previous extraction failed
    {
        if (std::cin.eof()) // If the stream was closed
        {
            std::exit(0); // Shut down the program now
        }

        // Let's handle the failure
        std::cin.clear(); // Put us back in 'normal' operation mode
        ignoreLine();     // And remove the bad input

        return true;
    }

    return false;
}

int getRandomNumber(int min, int max)
{
    std::uniform_int_distribution<> die6{min, max};
    return die6(Random::mt);
}

namespace WordList
{
    std::vector<std::string_view> words {
        "mystery",
        "broccoli" ,
        "account",
        "almost",
        "spaghetti",
        "opinion",
        "beautiful",
        "distance",
        "luggage"
    };
    
    std::string_view getRandomWord(){
        int index { getRandomNumber(0, static_cast<int>(words.size()-1)) };
        std::string_view word = words[static_cast<std::size_t>(index)];

        return word;
    }
};

class Session
{
private:
    std::vector<bool> m_displayedWord {};
    std::string_view m_word;
    std::size_t m_length {};
    std::vector<char> m_wrongGuesses {};
    int m_guessesLeft {};

    void setDisplayedWord() {
        for (std::size_t i { 0 }; i < m_length; i++)
        {
            m_displayedWord.push_back(false);
        }
    }
public:
    Session(std::string_view word)
    : m_word { word }, m_length { m_word.size() }, m_guessesLeft { 6 }
    {
        setDisplayedWord();
    }

    void displayWord()
    {
        std::cout << "The word: ";
        for (std::size_t i { 0 }; i < m_length; i++)
        {
            if (m_displayedWord[i]) {
                std::cout << m_word[i];
            } else {
                std::cout << "_";
            }
        }
        std::cout << '\t';
    }

    char getUserInput()
    {
        while(true)
        {
            std::cout << "Enter your next letter: ";
            char letter {};
            std::cin >> letter;

            if (clearFailedExtraction()) {
                std::cout << "You entered wrong input: " << letter << '\n';
                continue;
            }

            if (!std::isalpha(letter)) {
                std::cout << "That wasn't a valid input. Try again \n";
                continue;
            }

            ignoreLine();

            std::cout << "You entered " << letter << '\n';

            return letter;
        }
    }

    void findLetters(char guess)
    {
        bool found { false };
        for (int i { 0 }; i < static_cast<int>(m_length); i++)
        {
            auto index = static_cast<std::size_t>(i);
            if (m_word[index] == guess) {
                if (!m_displayedWord[index]) {
                    m_displayedWord[index] = true;
                    found = true;
                } else {
                    std::cout << "You already guessed that.  Try again.\n";
                    return;
                }
            }
        }

        if (found) {
            std::cout << "Yes, '" << guess << "' is in the word\n";
        } else {
            m_guessesLeft--;
            std::cout << "No, '" << guess << "' is not in the word!\n";
            m_wrongGuesses.push_back(guess);
        }
    }

    void printWrongResults()
    {
        for (int i {0}; i <= m_guessesLeft;i++) {
            std::cout << "+";
        }

        for (char guess : m_wrongGuesses) {
            std::cout << guess;
        }
    }

    void checkCompletenes() {
        for (bool isGuessed : m_displayedWord) {
            if (!isGuessed) {
                return;
            }
        }
        std::cout << "You won! Word was: " << m_word;
        std::exit(0);
    }

    void startGame()
    {
        while (m_guessesLeft >= 0) {
            displayWord();
            printWrongResults();
            std::cout << "\n";
            char guess { getUserInput() };
            findLetters(guess);
            checkCompletenes();
        }
        std::cout << "You lost! Word was: " << m_word;
    }
};


int main()
{
    printRules();
    std::string_view randomWord { WordList::getRandomWord() };

    Session session { randomWord };

    session.startGame();

    return 0;
}