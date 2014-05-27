#ifndef PLAY_HPP
#define PLAY_HPP

#include <array>
#include "Trump.hpp"
#include "Trick.hpp"
#include "../ui/Observable.hpp"
#include <vector>

namespace model
{

class Play : public ui::Observable<Play>
{
public:
	/* Przyjmuje: kolor atutowy, ID rozgrywajacego.
	 */
	Play(Trump trump, int firstPlayerID);
	
	Trump getTrump() { return trump; }
	
	int getBeginningPlayer() { return beginningPlayer; }
	void setBeginningPlayer(int player) { beginningPlayer = player; }
	
	int getPrimaryBeginningPlayer() { return primaryBeginningPlayer; }
	
	int getScoreOf(int player) { return tricksCollected[player]; }
	void incrementPlayerScore(int player) { tricksCollected[player]++; }
	
	Trick const & getTrick(int i) { return tricks[i]; }
	void addTrick(Trick trick) { tricks.push_back(trick); }
	int trickCount() { return tricks.size(); }
	
  	int getResult();
  	
	Trick currentTrick;
	
private:
	
  	Trump trump;
  	int beginningPlayer; 						// gracz zaczynajacy nastepna lewe
  	int primaryBeginningPlayer;					// gracz, ktory zaczynal pierwsza lewe gry
  	std::array<int, 4> tricksCollected;
  	std::vector<Trick> tricks;					// lewy danej gry
};

} // namespace model

#endif
