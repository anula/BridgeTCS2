#include "DummyComputerPlayer.hpp"
#include "model/Call.hpp"

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
	return Call::createPass();
}

