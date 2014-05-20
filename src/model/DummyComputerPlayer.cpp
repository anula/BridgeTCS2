#include "DummyComputerPlayer.hpp"
#include "model/Call.hpp"

using namespace model;

Card DummyComputerPlayer::getCard(Hand & hand, Bidding const & bidding, Play const & play)
{
	//TODO
}

Call DummyComputerPlayer::getCall(Hand const & hand, Bidding const & bidding)
{
	return Call::createPass();
}

