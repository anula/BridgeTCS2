#include "Play.hpp"

void Play::play()
{
	for (int i = 0; i < 13; i++)
	{
		// stwórz nową lewę
		Trick trick = Trick();
		// wypełnij ją kartami
		for (int j = playState.getBeginningPlayer(), k = 0; k < 4; j = (j+1)%4, k++)
		{
			trick.addCardAt(this->arbiters[j].getCard(), j);
		}
		// lewa pełna: dowiedz się, kto zbiera lewę
		int winner = this->resolveTrick(trick);
		// zwiększ liczbę lew tego playera
		playState.incrementPlayerScore(winner);
		// ustaw zwycięzcę nowym rozgrywającym
		playState.setBeginningPlayer(winner);
		// zapisz lewę do stanu gry
		playState.addTrick(std::move(trick));
	}	
}	

int Play::getResult()
{
	if(playState.trickCount() < 13)
		return -1;
	int fp = (playState.getPrimaryBeginningPlayer() + 1) % 4;
	return playState.getScoreOf(fp) + playState.getScoreOf((fp+2) % 4);
}

int Play::resolveTrick(Trick const & trick)
{
	return trick.resolve(playState.getTrump());
}
