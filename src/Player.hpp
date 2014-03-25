#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <stdexcept>
#include "Card.hpp"
//#include "Call.hpp"

class Player
{
public:		
	explicit Player(std::string _name) : name(_name) {}	
	
	std::string getName();
	Card getCard(int suit);  //suit - ograniczenie do dodania karty
//	Call getCall();
	void addCard(Card card); // karta do dodania do reki
	
private:
	std::string name;
};

struct EmptyHandException : std::logic_error
{
	explicit EmptyHandException() : std::logic_error("Cannot get card from empty hand.") {}
};

struct FullHandException : std::logic_error
{
	explicit FullHandException() : std::logic_error("Cannot add card to full hand.") {}
};

#endif
