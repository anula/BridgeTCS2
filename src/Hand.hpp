#ifndef HAND_HPP
#define HAND_HPP

#include "Card.hpp"
#include "Call.hpp"
#include "Role.hpp"
#include <vector>
#include <stdexcept>


namespace model
{

class Hand : protected std::vector<Card> 
{
public:
	Card getCard(int index);
	void addCard(Card card);
	int size(){ return this->size(); }
	static const int MAX_SIZE = 13;
	const std::vector<Card>& getCards() const;
};


struct FullHandException : std::logic_error
{
	explicit FullHandException() : std::logic_error("This player's hand is full.") {}
};

struct EmptyHandException : std::logic_error
{
	explicit EmptyHandException() : std::logic_error("This Player's hand is empty.") {}
};

struct NumberOutOfBounds : std::logic_error
{
	explicit NumberOutOfBounds() : std::logic_error("This index makes no fucking sense.") {}
};

} // namespace model

#endif
