#pragma once
#include <algorithm>
#include <vector>
#include "Card.hpp"

class IDeck
{
public:
    virtual ~IDeck() {};
    virtual void shuffle() = 0;
    virtual Card getCard() = 0;
    virtual int count() = 0;
};

class Deck : public IDeck
{
public:
    virtual ~Deck() {};
    void shuffle();
    Card getCard();
    int count();
protected:
    Deck() = default;
    std::vector<Card> deck;
};

class Standard52Deck : public Deck 
{
public:
    ~Standard52Deck() {}
    Standard52Deck(); 
};
