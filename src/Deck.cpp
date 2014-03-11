#include "Deck.hpp"

void Deck::shuffle()
{
    std::random_shuffle(deck.begin(), deck.end());
}

Card Deck::getCard()
{
    return deck.back();
}

int Deck::count()
{
    return deck.size();
}

Standard52Deck::Standard52Deck()
{
    for(int i = ONE; i <= ACE; i++)
    {
        for(int j = CLUBS; j <= SPADES; j++)
        {
            deck.push_back(Card(static_cast<Rank>(i), static_cast<Suit>(j)));
        }
    }
}
