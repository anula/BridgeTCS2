#ifndef TRICK_HPP
#define TRICK_HPP

#include <array>
#include "Card.hpp"
#include "Trump.hpp"
//#include "../ui/Observable.hpp"
#include <vector>

namespace model
{

class Trick //: public ui::Observable<Trick>
{
public:
	Trick () {}
	Trump getTrump() const;
	int getSize() const { return cards.size(); }
	int resolve(Trump trump) const;
	void addCard(Card card) { cards.push_back(card); }
	const std::vector<Card>& getCards() const { return cards; }
private:
	std::vector<Card> cards;
};

} // namespace model

#endif
