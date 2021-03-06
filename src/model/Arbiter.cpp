#include "Arbiter.hpp"

using namespace model;

Call Arbiter::getCall(Bidding const & bidding)
{
	Call call;
	while(true){
		call = player.getCall(hand, bidding);
		if(bidding.getCurrentConstraint().satisfies(call))
			break;
	}
	return call;
}

Card Arbiter::askPlayer(IPlayer & pplayer, Play const & play, Bidding const & bidding)
{
	int cardnum = -1;
	const std::vector<Card>& h = hand.getCards();
	do{
		Card rec = role != Role::DUMMY ? pplayer.getCard(hand, bidding, play) :
                                         pplayer.getDummyCard(hand, bidding, play);
		for(int i = 0; i < h.size(); ++i)
			if(h[i] == rec)
				cardnum = i;
		if(cardnum == -1)
			continue;
		else if(!validateCard(rec, h, play))
			cardnum = -1;
	}while(cardnum == -1);
	
	return hand.getCard(cardnum);
}

Card Arbiter::getCard(Bidding const & bidding, Play const & play)
{
	if(role != Role::DUMMY)
		return askPlayer(player, play, bidding);
	else
		return askPlayer(partner, play, bidding);
}

void Arbiter::addCard(Card newCard)
{
	hand.addCard(newCard);
}

bool Arbiter::validateCard(Card const & cc, std::vector<Card> const & hh, Play const & play) const
{
	Trump t = play.getCurrentTrick().getTrump();
	
	if(t == Trump::NT)
		return true;
	
	if(cc.suit == t)
		return true;
	
	for(int i = 0; i < (int)hh.size(); ++i)
		if(hh[i].suit == t)
			return false;
	
	return true;
}
