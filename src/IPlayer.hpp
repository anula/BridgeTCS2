#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <stdexcept>
#include <vector>
#include "Card.hpp"
#include "Call.hpp"

class IPlayer
{
public:
	virtual int getCard(std::vector<CardPtr> & hand) = 0; 
	virtual Call getCall() = 0;
};

#endif
