#ifndef CARD_HPP
#define CARD_HPP

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
	friend class Deck;
	
    const Suit suit;
    const Rank rank;

private:
    Card(Rank r, Suit s) : rank(r), suit(s) {}
};

#endif // CARD_HPP
