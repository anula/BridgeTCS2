#ifndef ARBITER_HPP
#define ARBITER_HPP

#include "Card.hpp"
#include "Call.hpp"
#include "IPlayer.hpp"
#include "Role.hpp"
#include "BiddingConstraint.hpp"
#include "Hand.hpp"
#include <vector>

namespace model
{

class Arbiter{
public:
	
	Arbiter(IPlayer & player, IPlayer & partner): 
		player(player), 
		partner(partner) {}
	
	Call getCall(BiddingConstraint constraint); // proxy getcall do playera
	Card getCard(Trump trickColor); // proxy getcard do playera
	void addCard(Card newCard); // dodaj karte do reki
	void setRole(Role newrole) { role = newrole; }
	Role getRole() { return role; }
	
private:
	
	Card askPlayer(); // popros playera o dodanie karty
	Card askPartner(); // pozwol partnerowi wziac karte
	
	Role role;
	
	IPlayer& player;
	IPlayer& partner;

	Hand hand;	
};


} // namespace model

#endif
