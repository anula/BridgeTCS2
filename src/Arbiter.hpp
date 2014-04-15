#ifndef ARBITER_HPP
#define ARBITER_HPP

#include "Card.hpp"
#include "Call.hpp"
#include "Player.hpp"
#include "Role.hpp"
#include <vector>

class Arbiter{
public:
	
	Arbiter(Player & player, Player & ppartner): 
		referredPlayer(player), 
		partner(ppartner) {}
	
	Call getCall(); // proxy getcall do playera
	Card getCard(); // proxy getcard do playera
	void addCard(Card newCard); // dodaj karte do reki
	void setRole(Role newrole) { role = newrole; }
	Role getRole() { return role; }
	
private:
	
	Card getReferredCard(std::vector<Card> hand); // popros playera o dodanie karty
	Card getCardByPartner(std::vector<Card> hand); // pozwol partnerowi wziac karte
	
	Role role;
	
	Player referredPlayer;
	Player partner;
	
	std::vector<Card> hand;	
};


struct EmptyHandException : std::logic_error
{
	explicit EmptyHandException() : std::logic_error("This player's hand is empty.") {}
};

struct FullHandException : std::logic_error
{
	explicit FullHandException() : std::logic_error("This player's hand is full.") {}
};

struct NumberOutOfBounds : std::logic_error
{
	explicit NumberOutOfBounds() : std::logic_error("Card number is wrong.") {}
};

#endif
