#ifndef TRICK_HPP
#define TRICK_HPP

#include <array>
#include "Card.hpp"
#include "Trump.hpp"
#include <vector>

class Trick
{
public:
	Trick () : hasColor(false)	{}
	void addCardAt(CardPtr && card, int i);
	inline CardPtr getCardAt(int i)
	{
		return std::move(this->cards[i]);
	}
	int resolve(Trump trump) const;
private:
	Suit colorOfTrick;
	bool hasColor;
	std::array<CardPtr, 4> cards;
};

#endif
