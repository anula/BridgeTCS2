#ifndef GAME_HPP
#define GAME_HPP
#include "Player.hpp"
#include "Arbiter.hpp"
#include<string>
#include<array>

class Game{
	
public:
	
	Game(Player& p1, Player& p2, Player& p3, Player& p4);
	void startGame(int starter);
	
private:
	
	std::array<Arbiter, 4> arbiters;
};


#endif // GAME_HPP
