#ifndef TRICK_HPP
#define TRICK_HPP

#include <array>
#include "Card.hpp"
#include "Trump.hpp"
#include <vector>

class Trick
{
public:
	Suit colorOfTrick;
	bool hasColor;
	Trick () : hasColor(false)	{}
	void addCardAt(Card* card, int i)
	{
		this->cards[i] = card;
		if (this->hasColor == false) {
			this->hasColor = true;
			this->colorOfTrick = card->suit;		
		}
	}
	Card* getCardAt(int i)
	{
		return this->cards[i];
	}
	int resolve(Trump trump);
private:
	std::array<Card*, 4> cards;
};

#endif
