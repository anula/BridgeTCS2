#include <algorithm>
#include <vector>
#include <memory>
#include "Deck.hpp"

using namespace model;

void Deck::shuffle()
{
    std::random_shuffle(deck.begin(), deck.end());
}

Card Deck::getCard()
{
    auto card = deck.back();
    deck.pop_back();
    return card;
}

int Deck::count() const
{
    return deck.size();
}

Card Deck::generateCard(Rank rank, Suit suit)
{
    return Card(rank, suit);
}

Standard52Deck::Standard52Deck()
{
    for(int i = 0; i < 13; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            deck.push_back(generateCard(static_cast<Rank>(i), static_cast<Suit>(j)));
        }
    }
}
