#ifndef DUMMY_COMPUTER_PLAYER_HPP
#define DUMMY_COMPUTER_PLAYER_HPP

#include <IPlayer.hpp>

class DummyComputerPlayer : IPlayer
{
public:
	int getCard(std::vector<CardPtr> & hand); 
	Call getCall();
}

#endif
