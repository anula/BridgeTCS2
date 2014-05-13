#ifndef HAND_HPP
#define HAND_HPP

#include "Card.hpp"
#include "Call.hpp"
#include "Role.hpp"
#include <vector>
#include <stdexcept>


namespace model
{

class Hand : public std::vector<Card> {
public:
	Card getCard(int index);
	void addCard(Card card);
	static const int MAX_SIZE = 13;
	const std::vector<Card>& getCards() const;
};


struct FullHandException : std::logic_error
{
	explicit FullHandException() : std::logic_error("This player's hand is full.") {}
};

struct OutOfHandException : std::logic_error
{
	explicit OutOfHandException() : std::logic_error("This index is out of player's hand.") {}
};

} // namespace model

#endif
