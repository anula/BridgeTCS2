#ifndef HAND_HPP
#define HAND_HPP

#include "Card.hpp"
#include "Call.hpp"
#include "IPlayer.hpp"
#include "Role.hpp"
#include <vector>


class Hand : protected std::vector<CardPtr> {
public:
	CardPtr getCard(int index);
	void addCard(CardPtr && card);
	static const int MAX_SIZE = 13;
	const std::vector<CardPtr>& getCards() const;
};


struct FullHandException : std::logic_error
{
	explicit FullHandException() : std::logic_error("This player's hand is full.") {}
};

struct OutOfHandException : std::logic_error
{
	explicit OutOfHandException() : std::logic_error("This index is out of player's hand.") {}
};

#endif
