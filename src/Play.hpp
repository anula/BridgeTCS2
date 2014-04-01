#ifndef PLAY_HPP
#define PLAY_HPP

#include <array>
#include "Card.hpp"
#include "Trump.hpp"
#include "Arbiter.hpp"
#include <vector>

class Trick
{
public:
	Suit colorOfTrick;
	bool hasColor;
	Trick () : hasColor(false)	{}
	void addCardAt(Card card, int i)
	{
		this->cards[i] = card;
		if (this->hasColor == false) {
			this->hasColor = true;
			this->colorOfTrick = card.suit;		
		}
	}
	Card getCardAt(int i)
	{
		return this->cards[i];
	}
	int resolve(Trump trump);
private:
	std::array<Card, 4> cards;
};

class Play
{
public:
	/* Przyjmuje: kolor atutowy, ID rozgrywajacego.
	 */
	Play(Trump trump, int firstPlayerID, std::array<Arbiter, 4> const & arbiters) : trump(trump), beginningPlayer(firstPlayerID), primaryBeginningPlayer(firstPlayerID), arbiters(arbiters)
	{
		this->tricksCollected.fill(0);
	}
	/* Przeprowadza rozgrywke.
	 */
	void play();	
	/* Zwraca liczbe lew zebranych przez pare rozgrywajaca.
	 */
	int getResult();
private:
    
    Trump trump;
    int beginningPlayer; 						// gracz zaczynajacy nastepna lewe
    int primaryBeginningPlayer;					// gracz, który zaczynał pierwszą lewę gry
    std::array<Arbiter, 4> const & arbiters;	// arbitrzy graczy
    std::array<int, 4> tricksCollected;
    std::vector<Trick> tricks;					// lewy danej gry
	 
	 /* Przyjmuje: referencję na lewę
	  *
	  * Zwraca: numer gracza, który dostał lewę
	  */
	 int resolveTrick(Trick const & trick);
};

#endif
