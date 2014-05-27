#include "Deal.hpp"
#include "Trick.hpp"
#include "Play.hpp"

using namespace model;

void Deal::perform() {
  Standard52Deck deck;
  deck.shuffle();
  for (int i = 0; deck.count() > 0; i++) {
    arbiters[(firstPlayer+i)%4].addCard(std::move(deck.getCard()));
  }

  int declarer;

  declarer = performBidding();
  biddingFinished = true;
  sigModified(*this);
  if (contract.value == 0) { // everyone passed
    dealResult.contract = contract;
    dealResult.tricksCollected = 0;
    return;
  }

  int tricksCollected = performPlay(declarer);
  dealResult.tricksCollected = tricksCollected;
  playFinished = true;
  sigModified(*this);
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
    if (i == 1)
    {
      play.setDummyHand(&arbiters[i].getHand());
    }
		Trick currentTrick = play.newTrick();
		
		for (int j = play.getBeginningPlayer(), k = 0; k < 4; j = (++j)%4, k++)
		{
			currentTrick.addCard(arbiters[j].getCard(bidding, play));
		}
		
		int winner = currentTrick.resolve(play.getTrump());
		play.incrementPlayerScore(winner);
		
		play.setBeginningPlayer(winner);
	}	

  return play.getResult();
}
