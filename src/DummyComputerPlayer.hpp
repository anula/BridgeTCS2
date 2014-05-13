#ifndef DUMMY_COMPUTER_PLAYER_HPP
#define DUMMY_COMPUTER_PLAYER_HPP

#include "IPlayer.hpp"

namespace model
{

class DummyComputerPlayer : IPlayer
{
     int getCard(Hand const & hand, Bidding const & bidding, Game const & game);
     Call getCall(Hand const & hand, Bidding const & bidding);
};

} // namespace model

#endif
