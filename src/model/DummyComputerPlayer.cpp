#include "DummyComputerPlayer.hpp"
#include "model/Call.hpp"

using namespace model;

Card DummyComputerPlayer::getCard(Hand const & hand, Bidding const & bidding, Play const & play) const
{
	const std::vector<Card>& h = hand.getCards();
    for(auto & card : h) {
        if(static_cast<Trump>(card.suit) == play.getCurrentTrick().getTrump())
            return card;
    }
	return h[0];
}

Card DummyComputerPlayer::getDummyCard(Hand const & hand, Bidding const & bidding, Play const & play) const
{
    return getCard(hand, bidding, play);
}

Call DummyComputerPlayer::getCall(Hand const & hand, Bidding const & bidding) const
{
	return Call::createPass();
}

