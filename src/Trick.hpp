#ifndef TRICK_HPP
#define TRICK_HPP

#include <array>
#include "Card.hpp"
#include "Trump.hpp"
#include <vector>

namespace model
{

class Trick
{
public:
	Trick () : hasColor(false)	{}
	void addCardAt(CardPtr && card, int i);
	inline Card const & getCardAt(int i)
	{
		return *cards[i];
	}
	int resolve(Trump trump) const;
private:
	Suit colorOfTrick;
	bool hasColor;
	std::array<CardPtr, 4> cards;
};

} // namespace model

#endif
