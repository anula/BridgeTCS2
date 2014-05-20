#include "DummyComputerPlayer.hpp"
#include "model/Call.hpp"

using namespace model;

Card DummyComputerPlayer::getCard(Hand const & hand, Bidding const & bidding, Play const & play)
{
	
}

Call DummyComputerPlayer::getCall(Hand const & hand, Bidding const & bidding)
{
	return Call::createPass();
}

