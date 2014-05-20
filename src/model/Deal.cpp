#include "Deal.hpp"
#include "Trick.hpp"
#include "Play.hpp"

using namespace model;

void Deal::perform() {
  Standard52Deck deck;
  deck.shuffle();
  for (int i = 0; i < deck.count(); i++) {
    arbiters[(firstPlayer+i)%4].addCard(std::move(deck.getCard()));
  }

  int declarer;

  declarer = performBidding();
  if (contract.value == 0) { // everyone passed
    dealResult.contract = contract;
    dealResult.tricksCollected = 0;
    return;
  }

  int tricksCollected = performPlay(declarer);
  dealResult.tricksCollected = tricksCollected;
}

int Deal::performBidding() {
  //bidding = Bidding();
  int who = firstPlayer;
  while (bidding.stillGoing()) {
    BiddingConstraint constraint = bidding.getCurrentConstraint();
    Call call = arbiters[who].getCall(bidding);
    bool callSucceed = bidding.makeCall(call);
    if (!callSucceed) // should not happen
      throw 666;
    who++;
    who %= 4;
  }
  this->contract = bidding.getContract();

  return (firstPlayer + bidding.getDeclarer())%4;
}

int Deal::performPlay(int declarer) {
  Play play(contract.trump, declarer);

	for (int i = 0; i < 13; i++)
	{
		// stwórz nową lewę
		Trick trick = Trick();
		// wypełnij ją kartami
		for (int j = play.getBeginningPlayer(), k = 0; k < 4; j = (j+1)%4, k++)
		{
			trick.addCardAt(arbiters[j].getCard(bidding, play), j);
		}
		// lewa pełna: dowiedz się, kto zbiera lewę
		int winner = trick.resolve(play.getTrump());
		// zwiększ liczbę lew tego playera
		play.incrementPlayerScore(winner);
		// ustaw zwycięzcę nowym rozgrywającym
		play.setBeginningPlayer(winner);
		// zapisz lewę do stanu gry
		play.addTrick(std::move(trick));
	}	

  return play.getResult();
}
