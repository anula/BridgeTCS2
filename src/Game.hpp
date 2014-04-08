#ifndef GAME_HPP
#define GAME_HPP
#include "Player.hpp"
#include "Arbiter.hpp"
#include<string>
class Game{
	
public:
	
	Game();
	void startGame(int starter);
	
private:
	
	Player players[4];
	Arbiter arbiters[4];
};


#endif // GAME_HPP
