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
    virtual ~Deck() = 0;
    void shuffle();
    Card getCard();
    int count();
protected:
    std::vector<Card> deck;
};

Deck::~Deck() {}

class Standard52Deck : public Deck 
{
public:
    ~Standard52Deck() {}
    Standard52Deck(); 
};
