#include "Player.hpp"
#include <string>

usint namespace model;

std::string Player::getName()
{
	return name;
}

Card Player::getCard(const Hand & hand)
{
	return 0; // TODO
}

Call Player::getCall()
{
	return Call(); // TODO
}

