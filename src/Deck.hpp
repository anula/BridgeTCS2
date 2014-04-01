#pragma once
#include "Card.hpp"
#include <vector>
#include <memory>
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
    std::unique_ptr<Card> generateCard(Rank rank, Suit suit);
    std::vector< std::unique_ptr<Card> > deck;
};

class Standard52Deck : public Deck 
{
public:
    ~Standard52Deck() {}
    Standard52Deck(); 
};
