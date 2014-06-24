#ifndef PLAY_HPP
#define PLAY_HPP

#include <array>
#include "Trump.hpp"
#include "Trick.hpp"
#include "Hand.hpp"
#include "../ui/Observable.hpp"
#include <vector>

namespace model
{

class Play : public ui::Observable<Play>
{
public:

	enum State {
		INITIAL, NEWWINNER
	};

	State state;

	/* Przyjmuje: kolor atutowy, ID rozgrywajacego.
	 */
	Play(Trump trump, int firstPlayerID);
	
	Trump getTrump() { return trump; }
	
	int getBeginningPlayer() const { return beginningPlayer; }
	
	void setBeginningPlayer(int player) { 
		beginningPlayer = player; 
		state=NEWWINNER;
		sigModified(*this);
		state=INITIAL;
	}
	
	int getPrimaryBeginningPlayer() const { return primaryBeginningPlayer; }
	
	int getScoreOf(int player) { return tricksCollected[player]; }
	
	void incrementPlayerScore(int player) { 
		tricksCollected[player]++;
	}
	
	Trick const & getTrick(int i) { return tricks[i]; }
	void addTrick(Trick trick) { tricks.push_back(trick); }
  	int trickCount() { return tricks.size(); }

  	int getResult();

  	Trick const & getCurrentTrick() const {
		return tricks.back();
	}

    std::vector<Trick> const & getTricksHistory() const {
        return tricks;
    }

	Trick & newTrick() {
		tricks.emplace_back();
		return tricks.back();
	}

  void setDummyHand(Hand const * hand) {
    dummyhand = hand;
  }

  Hand const * getDummyHand() const {
    return dummyhand;
  }

private:
	
  	Trump trump;
  	int beginningPlayer; 						// gracz zaczynajacy nastepna lewe
  	int primaryBeginningPlayer;					// gracz, ktory zaczynal pierwsza lewe gry
    Hand const * dummyhand;
  	std::array<int, 4> tricksCollected;
  	std::vector<Trick> tricks;					// lewy danej gry
};

} // namespace model

#endif
