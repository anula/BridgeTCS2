#include "Arbiter.hpp"
#include "IPlayer.hpp"
#include <vector>

using namespace model;

Call Arbiter::getCall(BiddingConstraint constraint)
{
	return player.getCall();
}

Card Arbiter::askPlayer()
{
	int cardnum = -1;
	const std::vector<Card>& h = hand.getCards();
	do{
		Card rec = player.getCard(hand);
		for(int i = 0; i < h.size(); ++i)
			if(h[i] == rec)
				cardnum = i;
	}while(cardnum == -1);
	// jakos sprawdz, czy hand[cardnum] jest poprawna karta
	if(cardnum >= (int)hand.size() || cardnum < 0)
		throw NumberOutOfBounds();
		
	Card card = hand.getCard(cardnum);
	return card;
}

Card Arbiter::askPartner()
{
	int cardnum = -1;
	const std::vector<Card>& h = hand.getCards();
	do{
		Card rec = partner.getCard(hand);
		for(int i = 0; i < h.size(); ++i)
			if(h[i] == rec)
				cardnum = i;
	}while(cardnum == -1);
	// jakos sprawdz, czy hand[cardnum] jest poprawna karta
	if(cardnum >= (int)hand.size() || cardnum < 0)
		throw NumberOutOfBounds();
		
	Card card = hand.getCard(cardnum);
	return card;
}

Card Arbiter::getCard(Trump trickColor)
{
	
	if(hand.size() == 0)
		throw EmptyHandException();
		
	if(role != Role::DUMMY)
		return askPlayer();
	else
		return askPartner();
}

void Arbiter::addCard(Card newCard)
{
	
	if(hand.size() == 13)
		throw FullHandException();
		
	hand.addCard(newCard);
}
