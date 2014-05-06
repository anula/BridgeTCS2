#include "Arbiter.hpp"
#include "IPlayer.hpp"

Call Arbiter::getCall(BiddingConstraint constraint)
{
	return player.getCall();
}

CardPtr Arbiter::askPlayer()
{
	int cardnum = player.getCard(hand);
	// jakos sprawdz, czy hand[cardnum] jest poprawna karta
	if(cardnum >= (int)hand.size() || cardnum < 0)
		throw NumberOutOfBounds();
		
	CardPtr cptr = std::move(hand[cardnum]);
	return cptr;
}

CardPtr Arbiter::askPartner()
{
	int cardnum = partner.getCard(hand);
	// jakos sprawdz, czy hand[cardnum] jest poprawna karta
	if(cardnum >= (int)hand.size() || cardnum < 0)
		throw NumberOutOfBounds();
	CardPtr cptr = std::move(hand[cardnum]);
	return cptr;
}

CardPtr Arbiter::getCard(Trump trickColor)
{
	
	if(hand.size() == 0)
		throw EmptyHandException();
		
	if(role != Role::DUMMY)
		return askPlayer(hand);
	else
		return askPartner(hand);
}

void Arbiter::addCard(CardPtr && newCard)
{
	
	if(hand.size() == 13)
		throw FullHandException();
		
	hand.emplace_back(std::move(newCard));
}
