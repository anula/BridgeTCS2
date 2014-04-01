#include "Play.hpp"

bool operator == (Suit s, Trump t)
{
	return static_cast<Suit>(t) == s;
}

void Play::play()
{
	for (int i = 0; i < 13; i++)
	{
		// stwórz nową lewę
		Trick trick = this->Trick();
		// wypełnij ją kartami
		for (int j = this->beginningPlayer, k = 0; k < 4; j = (j+1)%4, k++)
		{
			trick[j] = this->arbiters[j].getCard();
		}
		// lewa pełna: dowiedz się, kto zbiera lewę
		int winner = this->resolveTrick(&trick);
		// zwiększ liczbę lew tego playera
		this->tricksCollected[winner]++;
		// ustaw zwycięzcę nowym rozgrywającym
		this->beginningPlayer = winner;
	}	
}	

int Play::getResult()
{
	int sum = 0;
	for (int i = 0; i < 4; i++)
		sum += this->tricksCollected[i];
	if (sum < 13)
		return -1;
	int fp = this->primaryBeginningPlayer;
	return this->tricksCollected[fp] + this->tricksCollected[(fp+2)%4];
}

int Play::resolveTrick(Trick const & trick)
{
	return trick.resolve(this->trump);
}

int Trick::resolve(Trump trump)
{
	// jeśli gramy z atu
	if (trump != Trump.NT) {
		int maximalTrump = -1;
		int maximalTrumpOwnerIndex = -1;
		// przejrzyj lewę
		for (int i = 0; i < 4; i++)
		{	// jeśli karta ma kolor atutowy
			if (this->cards[i].suit == trump) {
				if (static_cast<int>(this->cards[i].rank) > maximalTrump)
				{	// jeśli da się poprawić zwycięzcę, popraw
					maximalTrump = static_cast<int>(this->cards[i].rank);
					maximalTrumpOwnerIndex = i;						
				}
			}
		}
		if (maximalTrumpOwnerIndex != -1)
			return maximalTrumpOwnerIndex;
	}
	// jeśli gramy bez atu, lub w lewie nie ma atu
	int maximalColor = -1;
	int maximalColorOwnerIndex = -1;
	// przejrzyj lewę
	for (int i = 0; i < 4; i++)
	{	// jeśli karta ma kolor tej lewy
		if (this->cards[i].suit == this->colorOfTrick) {
			if (static_cast<int>(this->cards[i].rank) > maximalColor)
			{	// jeśli da się poprawić zwycięzcę, popraw
				maximalColor = static_cast<int>(this->cards[i].rank);
				maximalColorOwnerIndex = i;						
			}
		}
	}
	return maximalColorOwnerIndex;
}

