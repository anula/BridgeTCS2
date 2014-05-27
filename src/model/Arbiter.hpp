#ifndef ARBITER_HPP
#define ARBITER_HPP

#include "Card.hpp"
#include "Call.hpp"
#include "IPlayer.hpp"
#include "Role.hpp"
#include "BiddingConstraint.hpp"
#include "Hand.hpp"
#include "Play.hpp"
#include "Trump.hpp"
#include <vector>

namespace model
{

class Arbiter{
public:
	
	Arbiter(IPlayer & player, IPlayer & partner): 
		player(player), 
		partner(partner) {}
	
	Call getCall(Bidding const & bidding); // proxy getcall do playera
	Card getCard(Bidding const & bidding, Play const & play); // proxy getcard do playera
	void addCard(Card newCard); // dodaj karte do reki
	
	void setRole(Role newrole) { role = newrole; }
	Role getRole() { return role; }

  	Hand const & getHand() const { return hand; }
	
private:
	
	Card askPlayer(IPlayer const & player, Play const & play, Bidding const & bidding); // popros playera o dodanie karty
	bool validateCard(Card const & c, std::vector<Card> const & h, Play const & t) const;
	
	Role role;
	
	IPlayer& player;
	IPlayer& partner;

	Hand hand;	
};

} // namespace model

#endif
