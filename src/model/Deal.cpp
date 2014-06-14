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
  dealResult.contract = contract;
  if (contract.value == 0) { // everyone passed
	dealResult.tricksCollected = 0;
	return;
  }

  int tricksCollected = performPlay(declarer);
  dealResult.tricksCollected = tricksCollected;
  playFinished = true;
  sigModified(*this);
}

int Deal::performBidding() {
   	sigModified(*this);
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
    arbiters[(firstPlayer + bidding.getDeclarer() + 2)%4].setRole(model::Role::DUMMY);
	return (firstPlayer + bidding.getDeclarer())%4;
}

int Deal::performPlay(int declarer) {
 	play = new model::Play(contract.trump, declarer);
 	sigModified(*this);

	for (int i = 0; i < 13; i++)
	{
		Trick & currentTrick = play->newTrick();
		
		for (int j = play->getBeginningPlayer(), k = 0; k < 4; j = (++j)%4, k++)
		{
			currentTrick.addCard(arbiters[j].getCard(bidding, *play));
			if (i == 0 && k == 0) {
				play->setDummyHand(&arbiters[(firstPlayer + bidding.getDeclarer() + 2)%4].getHand());
			}
		}
		
		int winningCard = currentTrick.resolve(play->getTrump());
        int winner = (play->getBeginningPlayer() + winningCard) % 4;
		play->incrementPlayerScore(winner);
		
		play->setBeginningPlayer(winner);
	}

	int playResult = play->getResult();
	delete play;
	play = nullptr;
	
	return playResult;
}
