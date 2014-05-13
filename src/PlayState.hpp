#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP

#include <array>
#include "Trump.hpp"
#include "Trick.hpp"
#include <vector>

namespace model
{

class PlayState
{
public:
	/* Przyjmuje: kolor atutowy, ID rozgrywajacego.
	 */
	PlayState(Trump trump, int firstPlayerID) : trump(trump), beginningPlayer(firstPlayerID), primaryBeginningPlayer(firstPlayerID)
	{
		this->tricksCollected.fill(0);
	}
	Trump getTrump() {
		return trump;
	}
	int getBeginningPlayer() {
		return beginningPlayer;
	}
	void setBeginningPlayer(int player) {
		beginningPlayer = player;
	}
	int getPrimaryBeginningPlayer() {
		return primaryBeginningPlayer;
	}
	int getScoreOf(int player) {
		return tricksCollected[player];
	}
	void incrementPlayerScore(int player) {
		tricksCollected[player]++;
	}
	Trick const & getTrick(int i) {
		return tricks[i];
	}
	void addTrick(Trick && trick) {
		tricks.emplace_back(std::move(trick));
	}
	int trickCount() {
    return tricks.size();
  }
  int getResult()
  {
    if(trickCount() < 13)
      return -1;
    int fp = (getPrimaryBeginningPlayer() + 1) % 4;
    return getScoreOf(fp) + getScoreOf((fp+2) % 4);
  }

private:
  Trump trump;
  int beginningPlayer; 						// gracz zaczynajacy nastepna lewe
  int primaryBeginningPlayer;					// gracz, który zaczynał pierwszą lewę gry
  std::array<int, 4> tricksCollected;
  std::vector<Trick> tricks;					// lewy danej gry
};

} // namespace model

#endif
