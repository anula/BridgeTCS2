#include "Game.hpp"
#include "IPlayer.hpp"

using namespace model;

Game::Game(IPlayer &p1, IPlayer &p2, IPlayer &p3, IPlayer &p4): arbiters{{ {p1, p3}, {p2, p4},{p3, p1},{p4, p2} }}
{
}

void Game::startGame(int starter)
{
	//Deal deal(arbiters, starter);
	// GOGOGOGO
}
