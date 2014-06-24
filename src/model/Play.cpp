#include "Play.hpp"

using namespace model;

Play::Play(Trump trump, int firstPlayerID) : trump(trump), beginningPlayer(firstPlayerID), primaryBeginningPlayer(firstPlayerID), dummyhand(nullptr), state(INITIAL)
{
	this->tricksCollected.fill(0);
}


int Play::getResult()
{
	if(trickCount() < 13)
   		return -1;
   	int fp = (getPrimaryBeginningPlayer()) % 4;
    return getScoreOf(fp) + getScoreOf((fp+2) % 4);
}

