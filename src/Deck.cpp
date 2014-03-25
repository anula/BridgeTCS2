#include "Deck.hpp"

void Deck::shuffle()
{
    std::random_shuffle(deck.begin(), deck.end());
}

Card Deck::getCard()
{
    Card card = *deck.back();
    deck.pop_back();
    return card;
}

int Deck::count()
{
    return deck.size();
}

Standard52Deck::Standard52Deck()
{
    for(int i = 0; i < 13; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            deck.push_back(std::unique_ptr<Card>(new Card(static_cast<Rank>(i), static_cast<Suit>(j))));
        }
    }
}
