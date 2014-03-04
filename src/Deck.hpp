#pragma once
#include <algorithm>
#include <vector>
#include "Card.hpp"
class IDeck
{
public:
    virtual ~IDeck() {}
    virtual void shuffle() = 0;
    virtual Card getCard() = 0;
    virtual int count() = 0;
};

class Deck : public IDeck
{
public:
    void shuffle();
    Card getCard();
    int count();
private:
    std::vector<Card> deck;
    Deck() {}
};
