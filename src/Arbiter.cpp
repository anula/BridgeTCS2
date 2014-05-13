#include "Arbiter.hpp"
#include "IPlayer.hpp"

using namespace model;

Call Arbiter::getCall(Bidding const & bidding)
{
	return player.getCall(hand, bidding);
}

CardPtr Arbiter::askPlayer(Play const & play, Bidding const & bidding)
{
	int cardnum = player.getCard(hand, bidding, play);
	// jakos sprawdz, czy hand[cardnum] jest poprawna karta
	if(cardnum >= (int)hand.size() || cardnum < 0)
		throw NumberOutOfBounds();
		
	CardPtr cptr = std::move(hand[cardnum]);
	return cptr;
}

CardPtr Arbiter::askPartner(Play const & play, Bidding const & bidding)
{
	int cardnum = partner.getCard(hand, bidding, play);
	// jakos sprawdz, czy hand[cardnum] jest poprawna karta
	if(cardnum >= (int)hand.size() || cardnum < 0)
		throw NumberOutOfBounds();
	CardPtr cptr = std::move(hand[cardnum]);
	return cptr;
}

CardPtr Arbiter::getCard(Play const & play, Bidding const & bidding)
{
	
	if(hand.size() == 0)
		throw EmptyHandException();
		
	if(role != Role::DUMMY)
		return askPlayer(play, bidding);
	else
		return askPartner(play, bidding);
}

void Arbiter::addCard(CardPtr && newCard)
{
	
	if(hand.size() == 13)
		throw FullHandException();
		
	hand.emplace_back(std::move(newCard));
}
