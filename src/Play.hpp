#ifndef PLAY_HPP
#define PLAY_HPP

#ifndef TRICK_HPP
#include "Trick.hpp"
#endif

class Play
{
public:
	Play();
	
	/*
	 * Przyjmuje: ID gracza, ktory zaczyna.
	 *
	 * Wysyla do kolejnych graczy zadania dolozenia kart do lewy.
	 *
	 * Zwraca: lewe wypelniona kartami.
	 */
	 Trick newTrick(int PlayerID);
	
	/*
	 *	Zwraca liczbe lew zebranych przez pare rozgrywajaca.
	 */
	int getResult();
private:
    
};

#endif
