#include "DummyComputerPlayer.hpp"
#include "model/Call.hpp"

using namespace model;

int DummyComputerPlayer::getCard(Hand const & hand, Bidding const & bidding, Game const & game)
{
	return 0;
}

Call DummyComputerPlayer::getCall(Hand const & hand, Bidding const & bidding)
{
	return Call::createPass();
}

