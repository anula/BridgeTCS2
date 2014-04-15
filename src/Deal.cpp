#include "Deal.hpp"

void Deal::perform() {
  Standard52Deck deck;
  deck.shuffle();
  for (int i = 0; i < deck.count(); i++) {
    arbiters[(firstPlayer+i)%4].addCard(std::move(deck.getCard()));
  }


  int declarer;

  declarer = performBidding();
  if (contract.value == 0) {
    dealResult.contract = contract;
    dealResult.tricksCollected = 0;
    return;
  }

  int tricksCollected = performPlay(declarer);
  dealResult.tricksCollected = tricksCollected;
}

int Deal::performBidding() {
  Bidding bidding;
  int who = firstPlayer;
  while (bidding.stillGoing()) {
    BiddingConstraint constraint = bidding.getCurrentConstraint();
    Call call = arbiters[who].getCall(constraint);
    bool callSucceed = bidding.makeCall(call);
    if (!callSucceed) // should not happen
      throw 666;
  }
  contract = bidding.getContract();
  
  return (firstPlayer + bidding.getDeclarer())%4;
}

int Deal::performPlay(int declarer) {
  PlayState playState(contract.trump, declarer);
  Play play(playState, arbiters);
  play.play();
  return play.getResult();
}
