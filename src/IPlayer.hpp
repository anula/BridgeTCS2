#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <stdexcept>
#include <vector>
#include "Card.hpp"
#include "Call.hpp"
#include "Hand.hpp"

namespace model
{

class IPlayer
{
public:
	virtual int getCard(const Hand & hand) = 0; 
	virtual Call getCall() = 0;
};

} // namespace model

#endif
