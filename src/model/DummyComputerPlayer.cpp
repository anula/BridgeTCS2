#include <random>
#include <cmath>

#include "DummyComputerPlayer.hpp"
#include "model/Call.hpp"
#include "model/BiddingConstraint.hpp"

using namespace model;

Card DummyComputerPlayer::getCard(Hand const & hand, Bidding const & bidding, Play const & play)
{
    return strategy(hand, bidding, play);
}

Card DummyComputerPlayer::getDummyCard(Hand const & hand, Bidding const & bidding, Play const & play)
{
    return strategy(hand, bidding, play);
}

Card DummyComputerPlayer::strategy(Hand const & hand, Bidding const & bidding, Play const & play)
{
	const std::vector<Card>& h = hand.getCards();
    for(auto & card : h) {
        if(static_cast<Trump>(card.suit) == play.getCurrentTrick().getTrump())
            return card;
    }
	return h[0];
}
Call DummyComputerPlayer::getCall(Hand const & hand, Bidding const & bidding)
{
    BiddingConstraint biddConst = bidding.getCurrentConstraint();
	std::random_device rd;
	std::default_random_engine e1(rd());
	std::uniform_int_distribution<int> distVal(1, 4);
	std::uniform_int_distribution<int> distTru(0, 4);
    Call call = Call::createStandard(distVal(e1), static_cast<Trump>(distTru(e1)));
    if (biddConst.satisfies(call)) {
        return call;
    } else {
        return Call::createPass();
    }
}

