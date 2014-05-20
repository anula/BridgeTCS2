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
	Trick () {}
	Trump getTrump();
	int getSize() { return cards.size(); }
	int resolve(Trump trump) const;
	void addCard(Card card) { cards.push_back(card); }
private:
	std::vector<Card> cards;
};

} // namespace model

#endif
