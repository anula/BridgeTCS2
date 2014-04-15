#include "Game.hpp"
#include "Player.hpp"

Game::Game(Player p1, Player p2, Player p3, Player p4): arbiters{{ {p1, p3},{p2, p4},{p3, p1},{p4, p2} }}
{
}

void Game::startGame(int starter)
{
	//Deal deal(arbiters, starter);
	// GOGOGOGO
}
