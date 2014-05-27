#include "DummyComputerPlayer.hpp"
#include "model/Call.hpp"

using namespace model;

Card DummyComputerPlayer::getCard(Hand & hand, Bidding const & bidding, Play const & play) const
{
	return hand.getCard(0);
}

Call DummyComputerPlayer::getCall(Hand const & hand, Bidding const & bidding) const
{
	return Call::createPass();
}

