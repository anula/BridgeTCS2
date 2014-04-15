#include "Arbiter.hpp"
#include "Player.hpp"

Call Arbiter::getCall()
{
	return referredPlayer.getCall();
	// jakos sprawdz call
}

CardPtr Arbiter::askPlayer(std::vector<CardPtr> & hand)
{
	int cardnum = referredPlayer.getCard(hand);
	// jakos sprawdz, czy hand[cardnum] jest poprawna karta
	if(cardnum >= hand.size() || cardnum < 0)
		throw NumberOutOfBounds();
		
	CardPtr cptr = std::move(hand[cardnum]);
	return cptr;
}

CardPtr Arbiter::askPartner(std::vector<CardPtr> & hand)
{
	int cardnum = partner.getCard(hand);
	// jakos sprawdz, czy hand[cardnum] jest poprawna karta
	if(cardnum >= hand.size() || cardnum < 0)
		throw NumberOutOfBounds();
	return hand[cardnum];
}

Card Arbiter::getCard()
{
	
	if(hand.size() == 0)
		throw EmptyHandException();
		
	if(role != Role::DUMMY)
		return askPlayer(hand);
	else
		return askPartner(hand);
}

void Arbiter::addCard(Card newCard)
{
	
	if(hand.size() == 13)
		throw FullHandException();
		
	hand.push_back(newCard);
}
