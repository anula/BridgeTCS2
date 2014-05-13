#ifndef CARD_HPP
#define CARD_HPP

#include <memory>

namespace model
{

enum class Suit
{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES,
};

enum class Rank
{
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
};

struct Card
{
	Rank rank;
	Suit suit;
	
    Card(Rank r, Suit s) : rank(r), suit(s) {}
};

} // namespace model

#endif // CARD_HPP
