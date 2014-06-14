#ifndef DUMMY_COMPUTER_PLAYER_HPP
#define DUMMY_COMPUTER_PLAYER_HPP

#include "IPlayer.hpp"

namespace model
{

class DummyComputerPlayer : public IPlayer
{
     Card getCard(Hand const & hand, Bidding const & bidding, Play const & play) const;
     Card getDummyCard(Hand const & hand, Bidding const & bidding, Play const & play) const;
     Call getCall(Hand const & hand, Bidding const & bidding) const;
};

} // namespace model

#endif
