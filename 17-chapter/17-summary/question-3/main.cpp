#include <iostream>
#include <algorithm> // for std::shuffle
#include "Random.h"  // for Random::mt

struct Card
{
    enum Rank
    {
        rank_ace,
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,

        max_ranks
    };

    enum Suit
    {
        suit_club,
        suit_diamond,
        suit_heart,
        suit_spade,

        max_suits
    };

    Rank rank{};
    Suit suit{};

    static constexpr std::array<Rank, Rank::max_ranks> allRanks {
        Rank::rank_ace,
        Rank::rank_2,
        Rank::rank_3,
        Rank::rank_4,
        Rank::rank_5,
        Rank::rank_6,
        Rank::rank_7,
        Rank::rank_8,
        Rank::rank_9,
        Rank::rank_10,
        Rank::rank_jack,
        Rank::rank_queen,
        Rank::rank_king,
    };

    static constexpr std::array<Suit, Suit::max_suits> allSuits {
        Suit::suit_club, Suit::suit_diamond, Suit::suit_heart, Suit::suit_spade
    };

    static constexpr std::string_view getCardRank(Card::Rank rank)
    {
        switch(rank) {
            case Card::rank_ace: return "A";
            case Card::rank_jack: return "J";
            case Card::rank_queen: return "Q";
            case Card::rank_king: return "K";
            case Card::rank_2: return "2";
            case Card::rank_3: return "3";
            case Card::rank_4: return "4";
            case Card::rank_5: return "5";
            case Card::rank_6: return "6";
            case Card::rank_7: return "7";
            case Card::rank_8: return "8";
            case Card::rank_9: return "9";
            case Card::rank_10: return "10";
            default: return "???";
        }
    }

    static constexpr std::string_view getCardSuit(Card::Suit suit)
    {
        switch(suit) {
            case Card::suit_club: return "C";
            case Card::suit_diamond: return "D";
            case Card::suit_heart: return "H";
            case Card::suit_spade: return "S";
            default: return "???";
        }
    }

    static constexpr int getValue(Card::Rank rank)
    {
        switch(rank) {
            case Card::rank_ace: return 11;
            case Card::rank_2: return 2;
            case Card::rank_3: return 3;
            case Card::rank_4: return 4;
            case Card::rank_5: return 5;
            case Card::rank_6: return 6;
            case Card::rank_7: return 7;
            case Card::rank_8: return 8;
            case Card::rank_9: return 9;
            case Card::rank_10: return 10;
            case Card::rank_jack: return 10;
            case Card::rank_queen: return 10;
            case Card::rank_king: return 10;
            default: return -1;
        }
    } 

    friend std::ostream& operator<<(std::ostream& out, const Card &card)
    {
        out << Card::getCardRank(card.rank) << Card::getCardSuit(card.suit);
        return out;
    }
};

class Deck
{
private:
    std::array<Card, 52> m_cards{};
    std::size_t m_nextCard {0};

public:
    Deck()
    {
        std::size_t index {0};
        for (auto suit : Card::allSuits)
            for (auto rank : Card::allRanks)
            {
                m_cards[index] = Card{ rank, suit };
                index++;
            }
    }

    Card dealCard()
    {
        Card card {m_cards[m_nextCard]};

        if (m_nextCard == 52)
        {
            std::cout << card << " is a last card in deck\n";
            return card;
        }
        m_nextCard++;
        return card;
    }

    void shuffle()
    {
        std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
        m_nextCard = 0;
    }
};

int main()
{
    Card card { Card::rank_5, Card::suit_heart };
    std::cout << card << '\n';

    for (auto suit: Card::allSuits)
    {
        for (auto rank: Card::allRanks)
        {
            std::cout << Card { rank, suit } << ' ';
        }
    }

    std::cout << '\n';

    Deck deck{};

    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

    deck.shuffle();

    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

    return 0;
}