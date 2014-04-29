#ifndef HAND_HPP
#define HAND_HPP

#include "Card.hpp"
#include "Call.hpp"
#include "Player.hpp"
#include "Role.hpp"
#include <vector>

class Hand : protected vector<CardPtr> {
public:
	CardPtr getCard(int index);
	void addCard(CardPtr && card);
	const int MAX_SIZE;
};

struct FullHandException : std::logic_error
{
	explicit FullHandException() : std::logic_error("This player's hand is full.") {}
};


#endif
