#ifndef PLAY_HPP
#define PLAY_HPP

#include "Trick.hpp"
#include <array>

class Play
{
public:
	/* Przyjmuje: kolor atutowy, ID rozgrywajacego.
	 */
	Play(Trump trump, int firstPlayerID);
	
	/* Przeprowadza rozgrywke.
	 */
	void play();	
	/* Zwraca liczbe lew zebranych przez pare rozgrywajaca.
	 */
	int getResult();
private:
    using Trick = std::array<Card, 4>;
    
    Trump trump;
    int beginningPlayer; // gracz zaczynajacy nastepna lewe
    /* Przyjmuje: ID gracza, ktory zaczyna.
	 *
	 * Wysyla do kolejnych graczy zadania dolozenia kart do lewy.
	 *
	 * Zwraca: lewe wypelniona kartami.
	 */
	 Trick newTrick(int PlayerID);
};

#endif
