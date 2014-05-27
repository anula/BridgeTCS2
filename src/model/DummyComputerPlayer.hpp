#ifndef DUMMY_COMPUTER_PLAYER_HPP
#define DUMMY_COMPUTER_PLAYER_HPP

#include "IPlayer.hpp"

namespace model
{

class DummyComputerPlayer : public IPlayer
{
     Card getCard(Hand & hand, Bidding const & bidding, Play const & play);
     Call getCall(Hand const & hand, Bidding const & bidding);
};

} // namespace model

#endif
