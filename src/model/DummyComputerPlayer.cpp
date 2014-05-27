#include "DummyComputerPlayer.hpp"
#include "model/Call.hpp"

using namespace model;

Card DummyComputerPlayer::getCard(Hand const & hand, Bidding const & bidding, Play const & play) const
{
	const std::vector<Card>& h = hand.getCards();
	return h[0];
}

Call DummyComputerPlayer::getCall(Hand const & hand, Bidding const & bidding) const
{
	return Call::createPass();
}

