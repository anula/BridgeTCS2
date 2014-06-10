#ifndef HAND_HPP
#define HAND_HPP

#include "Card.hpp"
#include "Call.hpp"
#include "Role.hpp"
#include <vector>
#include <stdexcept>


namespace model
{

class Hand : protected std::vector<Card> {
public:
	Card getCard(int index);
	void addCard(Card card);
    using std::vector<Card>::size;
	static const int MAX_SIZE = 13;
	const std::vector<Card>& getCards() const;
};


struct FullHandException : std::logic_error
{
	explicit FullHandException() : std::logic_error("This player's hand is full.") {}
};

struct NumberOutOfBounds : std::logic_error
{
	explicit NumberOutOfBounds() : std::logic_error("This index makes no fucking sense.") {}
};

struct CardComparator {
	bool operator() (Card const & c1, Card const & c2) {
		return (c1.suit == c2.suit) ? (c1.rank < c2.rank) : (c1.suit < c2.suit);
	}
};

} // namespace model

#endif
