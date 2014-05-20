#ifndef SIMPLE_GAME_HPP
#define SIMPLE_GAME_HPP

#include "model/Game.hpp"
#include "model/IPlayer.hpp"

using namespace model;

class SimpleGame : public IGame
{
public:
	void start(int starter);
};

#endif
