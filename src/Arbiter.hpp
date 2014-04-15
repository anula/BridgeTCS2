#ifndef ARBITER_HPP
#define ARBITER_HPP

#include "Card.hpp"
#include "Call.hpp"
#include "Player.hpp"
#include "Role.hpp"
#include <vector>

class Arbiter{
public:
	
	explicit Arbiter(Player & player, Player & ppartner): 
		referredPlayer(player), 
		partner(ppartner) {}
	
	Call getCall(); // proxy getcall do playera
	CardPtr getCard(); // proxy getcard do playera
	void addCard(CardPtr && newCard); // dodaj karte do reki
	void setRole(Role newrole) { role = newrole; }
	Role getRole() { return role; }
	
private:
	
	CardPtr getReferredCard(std::vector<CardPtr> & hand);
	CardPtr getCardByPartner(std::vector<CardPtr> & hand);
	
	Role role;
	
	Player referredPlayer;
	Player partner;
	
	std::vector<CardPtr> hand;	
};


struct EmptyHandException : std::logic_error
{
	explicit EmptyHandException() : std::logic_error("This player's hand is empty.") {}
};

struct FullHandException : std::logic_error
{
	explicit FullHandException() : std::logic_error("This player's hand is full.") {}
};


#endif
