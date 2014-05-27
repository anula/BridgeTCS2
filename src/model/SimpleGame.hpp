#ifndef SIMPLE_GAME_HPP
#define SIMPLE_GAME_HPP

#include "model/Game.hpp"
#include "model/IPlayer.hpp"

using namespace model;

class SimpleGame : public IGame
{
public:
	SimpleGame(IPlayer& p1, IPlayer& p2, IPlayer& p3, IPlayer& p4)
			: IGame(p1, p2, p3, p4) {}
	
	void start(int starter);
};

#endif
