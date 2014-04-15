#ifndef PLAY_HPP
#define PLAY_HPP

#include "Card.hpp"
#include "Trump.hpp"
#include "Arbiter.hpp"
#include "Trick.hpp"
#include "PlayState.hpp"

class Play
{
public:
	/* Przyjmuje: kolor atutowy, ID rozgrywajacego.
	 */
	Play(PlayState & playState, std::array<Arbiter, 4> & arbiters) : playState(playState), arbiters(arbiters) {}
	/* Przeprowadza rozgrywke.
	 */
	void play();	
	/* Zwraca liczbe lew zebranych przez pare rozgrywajaca.
	 */
	int getResult();
private:
	PlayState & playState;
    std::array<Arbiter, 4> & arbiters;	// arbitrzy graczy 
	 /* Przyjmuje: referencję na lewę
	  *
	  * Zwraca: numer gracza, który dostał lewę
	  */
	int resolveTrick(Trick const & trick);
};

#endif
