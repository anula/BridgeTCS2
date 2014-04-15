#ifndef DECK_HPP
#define DECK_HPP

#include "Card.hpp"
#include <vector>
#include <memory>
class IDeck
{
public:
    virtual void shuffle() = 0;
    virtual std::unique_ptr<Card> getCard() = 0;
    virtual int count() = 0;
};

class Deck : public IDeck
{
public:
    void shuffle();
    std::unique_ptr<Card> getCard();
    int count();
protected:
    Deck() = default;
    std::unique_ptr<Card> generateCard(Rank rank, Suit suit);
    std::vector< std::unique_ptr<Card> > deck;
};

class Standard52Deck : public Deck 
{
public:
    Standard52Deck(); 
};

#endif // DECK_HPP
