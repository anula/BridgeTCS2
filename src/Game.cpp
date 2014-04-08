#include "Game.hpp"
#include "Player.hpp"

Game::Game(){
	for(int i = 0; i < 4; ++i)
		players[i] = Player("Player " + std::string(i));
}

void Game::startGame(int starter){
	//Deal deal(arbiters, starter);
	// GOGOGOGO
}
