#ifndef GAME_HPP
#define GAME_HPP
#include "IPlayer.hpp"
#include "Arbiter.hpp"
#include "Deal.hpp"
#include "../ui/Observable.hpp"
#include <string>
#include <array>

namespace model
{

class IGame : public ui::Observable<IGame>
{
	
public:
	
	IGame(IPlayer& p1, IPlayer& p2, IPlayer& p3, IPlayer& p4)
			: arbiters{{ {p1, p3}, {p2, p4}, {p3, p1}, {p4, p2} }} {}
	
	virtual void start(int starter=IGame::STARTING_PLAYER) = 0;
	DealResult result;
	
protected:
	
	std::array<Arbiter, 4> arbiters;

	static const int STARTING_PLAYER = 0;
};

} // namespace model

#endif // GAME_HPP
