#ifndef PLAYER_H_GUARD
#define PLAYER_H_GUARD

#include <string>
#include "Card.hpp"
//#include "Call.hpp"

class Player
{
public:		
	Player(std::string _name) : name(_name) {}	
	
	std::string getName();
	Card getCard(int suit);  //suit - ograniczenie do dodania karty
//	Call getCall();
	void addCard(Card card); // karta do dodania do reki
	
private:
	std::string name;
};

#endif
