void Deal::perform() {
  Standard52Deck deck;
  deck.shuffle();
  for (int i = 0; i < deck.count(); i++) {
    arbiters[(firstPlayer+i)%4].addCard(deck.getCard());
  }


  int declarer;

  declarer = performBidding();
  if (contract.value == 0) {
    result.contract = contract;
    result.tricksCollected = 0;
    return;
  }

  performPlay();
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
