#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <stdexcept>
#include <vector>
#include "Card.hpp"
#include "Call.hpp"

namespace model
{

class Player
{
public:	
	explicit Player(std::string _name) : name(_name) {}	
	
	std::string getName();
	int getCard(const Hand & hand); 
	Call getCall();
	
private:
	std::string name;
};

} // namespace model

#endif
