#include "DummyComputerPlayer.hpp"
#include "Call.hpp"

int DummyComputerPlayer::getCard(std::vector<CardPtr> & hand)
{
	return 0;
}

Call DummyComputerPlayer::getCall()
{
	return Call::createPass();
}

