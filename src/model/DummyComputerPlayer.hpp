#ifndef DUMMY_COMPUTER_PLAYER_HPP
#define DUMMY_COMPUTER_PLAYER_HPP

#include "IPlayer.hpp"

namespace model
{

class DummyComputerPlayer : public IPlayer
{
     Card getCard(Hand const & hand, Bidding const & bidding, Play const & play);
     Card getDummyCard(model::Hand const & hand, model::Bidding const & bidding, model::Play const & play);
     Call getCall(Hand const & hand, Bidding const & bidding);
private:
     Card strategy(Hand const & hand, Bidding const & bidding, Play const & play);
};

} // namespace model

#endif
