#ifndef CARD_HPP
#define CARD_HPP

#include <memory>

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
    Card(const Card &c) = delete;

	friend class Deck;
	
	const Rank rank;
    const Suit suit;

private:
    Card(Rank r, Suit s) : rank(r), suit(s) {}
};

using CardPtr = std::unique_ptr<Card>;

#endif // CARD_HPP
