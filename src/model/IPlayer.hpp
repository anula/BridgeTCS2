#ifndef IPLAYER_HPP
#define IPLAYER_HPP

#include <string>
#include <stdexcept>
#include <vector>
#include "Card.hpp"
#include "Call.hpp"
#include "Hand.hpp"
#include "Bidding.hpp"
#include "Play.hpp"

namespace model
{

class IPlayer
{
public:
	virtual Card getCard(Hand const & hand, Bidding const & bidding, Play const & play) = 0; 
    virtual Card getDummyCard(model::Hand const & hand, model::Bidding const & bidding, model::Play const & play) = 0;
	virtual Call getCall(Hand const & hand, Bidding const & bidding) = 0;
};

} // namespace model

#endif
