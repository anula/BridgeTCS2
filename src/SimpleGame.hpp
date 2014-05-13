#ifndef SIMPLE_GAME_HPP
#define SIMPLE_GAME_HPP

#include "model/Game.hpp"
#include "model/IPlayer.hpp"

using namespace model;

class SimpleGame : public IGame
{
public:
	SimpleGame(IPlayer & player1, IPlayer & player2, IPlayer & player3, IPlayer & player4)
			: IGame(player1, player2, player3, player4) {}
	
	void start(int starter);
};


#endif
