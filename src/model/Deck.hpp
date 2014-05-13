#ifndef DECK_HPP
#define DECK_HPP

#include "Card.hpp"
#include <vector>
#include <memory>
namespace model
{

class IDeck
{
public:
    virtual void shuffle() = 0;
    virtual Card getCard() = 0;
    virtual int count() const = 0;
};

class Deck : public IDeck
{
public:
    void shuffle();
    Card getCard();
    int count() const;
protected:
    Deck() = default;
    Card generateCard(Rank rank, Suit suit);
    std::vector<Card> deck;
};

class Standard52Deck : public Deck 
{
public:
    Standard52Deck(); 
};


} // namespace model

#endif // DECK_HPP
