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
    virtual std::unique_ptr<Card> getCard() = 0;
    virtual int count() const = 0;
};

class Deck : public IDeck
{
public:
    void shuffle();
    std::unique_ptr<Card> getCard();
    int count() const;
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


} // namespace model

#endif // DECK_HPP
