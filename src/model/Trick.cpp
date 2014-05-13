#include "Trick.hpp"

using namespace model;

bool operator == (Suit s, Trump t)
{
	return static_cast<Suit>(t) == s;
}

void Trick::addCardAt(Card card, int i)
{
	cards[i] = card;
	if (hasColor == false) {
		hasColor = true;
		colorOfTrick = card.suit;		
	}
}

int Trick::resolve(Trump trump) const
{
	// jeśli gramy z atu
	if (trump != Trump::NT) {
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

