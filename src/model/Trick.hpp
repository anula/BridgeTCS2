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
	Trick () : hasColor(false)	{}
	void addCardAt(Card card, int i);
	inline Card const & getCardAt(int i)
	{
		return cards[i];
	}
	int resolve(Trump trump) const;
private:
	Suit colorOfTrick;
	bool hasColor;
	std::vector<Card> cards;
	//std::array<Card, 4> cards;
};

} // namespace model

#endif
