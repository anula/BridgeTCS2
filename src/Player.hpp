#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <stdexcept>
#include <vector>
#include "Card.hpp"
#include "Call.hpp"

class Player
{
public:		
	explicit Player(std::string _name) : name(_name) {}	
	
	std::string getName();
	int getCard(std::vector<Card> hand); 
	Call getCall();
	
private:
	std::string name;
};
#endif
