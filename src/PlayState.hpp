#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP

#include <array>
#include "Trump.hpp"
#include "Trick.hpp"
#include <vector>


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
	Trick getTrick(int i) {
		return tricks[i];
	}
	void addTrick(Trick trick) {
		tricks.push_back(trick);
	}
	int trickCount() {
		return tricks.size();
	}
	
private:
    Trump trump;
    int beginningPlayer; 						// gracz zaczynajacy nastepna lewe
    int primaryBeginningPlayer;					// gracz, który zaczynał pierwszą lewę gry
    std::array<int, 4> tricksCollected;
    std::vector<Trick> tricks;					// lewy danej gry
};

#endif