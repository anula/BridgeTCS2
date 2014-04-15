#include "Arbiter.hpp"
#include "Player.hpp"

Call Arbiter::getCall(){
	return referredPlayer.getCall();
	// jakos sprawdz call
}

CardPtr Arbiter::getReferredCard(std::vector<CardPtr> & hand){
	int cardnum = referredPlayer.getCard(hand);
	// jakos sprawdz, czy hand[cardnum] jest poprawna karta
	return std::move(hand[cardnum]);
}

CardPtr Arbiter::getCardByPartner(std::vector<CardPtr> & hand){
	int cardnum = partner.getCard(hand);
	// jakos sprawdz, czy hand[cardnum] jest poprawna karta
	return std::move(hand[cardnum]);
}

CardPtr Arbiter::getCard(){
	
	if(hand.size() == 0)
		throw EmptyHandException();
		
	if(role != Role::DUMMY)
		return std::move(getReferredCard(hand));
	else
		return std::move(getCardByPartner(hand));
}

void Arbiter::addCard(CardPtr && newCard){
	
	if(hand.size() == 13)
		throw FullHandException();
		
	hand.emplace_back(std::move(newCard));
}

