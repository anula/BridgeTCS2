#include "Player.hpp"
#include <string>

usint namespace model;

std::string Player::getName()
{
	return name;
}

int Player::getCard(std::vector<CardPtr> & hand)
{
	return 0; // TODO
}

Call Player::getCall()
{
	return Call(); // TODO
}

