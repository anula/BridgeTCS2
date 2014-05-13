#ifndef GAME_HPP
#define GAME_HPP
#include "IPlayer.hpp"
#include "Arbiter.hpp"
#include<string>
#include<array>

namespace model
{

class Game{
	
public:
	
	Game(IPlayer& p1, IPlayer& p2, IPlayer& p3, IPlayer& p4);
	void startGame(int starter);
	
private:
	
	std::array<Arbiter, 4> arbiters;
};

} // namespace model

#endif // GAME_HPP
