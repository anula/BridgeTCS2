#include "Play.hpp"

Play::Play(Trump trump, int firstPlayerID)
{
	this->trump = trump;
	this->beginningPlayer = firstPlayerID;
}

void Play::play()
{
	
}	

int Play::getResult()
{
	return 0;
}

Trick Play::newTrick(int PlayerID)
{
	return Trick();
}
