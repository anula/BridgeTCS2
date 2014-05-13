#include "Arbiter.hpp"
#include "IPlayer.hpp"
#include <vector>

using namespace model;

Call Arbiter::getCall(Bidding const & bidding)
{
	return player.getCall(hand, bidding);
}

Card Arbiter::askPlayer(Play const & play, Bidding const & bidding)
{
	int cardnum = -1;
	const std::vector<Card>& h = hand.getCards();
	do{
		Card rec = player.getCard(hand, bidding, play);
		//check
		for(int i = 0; i < h.size(); ++i)
			if(h[i] == rec)
				cardnum = i;
	}while(cardnum == -1);
	
	return h[cardnum];
}

Card Arbiter::askPartner(Play const & play, Bidding const & bidding)
{
	int cardnum = -1;
	const std::vector<Card>& h = hand.getCards();
	do{
		Card rec = partner.getCard(hand, bidding, play);
		//check
		for(int i = 0; i < h.size(); ++i)
			if(h[i] == rec)
				cardnum = i;
	}while(cardnum == -1);
	
	return h[cardnum];
}

Card Arbiter::getCard(Bidding const & bidding, Play const & play)
{
	if(role != Role::DUMMY)
		return askPlayer(play, bidding);
	else
		return askPartner(play, bidding);
}

void Arbiter::addCard(Card newCard)
{
	hand.addCard(newCard);
}
