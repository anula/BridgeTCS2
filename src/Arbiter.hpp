#ifndef ARBITER_HPP
#define ARBITER_HPP

#include "Card.hpp"
#include "Call.hpp"
#include "IPlayer.hpp"
#include "Role.hpp"
#include "BiddingConstraint.hpp"
#include "Hand.hpp"
#include "Play.hpp"
#include <vector>

namespace model
{

class Arbiter{
public:
	
	Arbiter(IPlayer & player, IPlayer & partner): 
		player(player), 
		partner(partner) {}
	
	Call getCall(Bidding const & bidding); // proxy getcall do playera
	CardPtr getCard(Bidding const & bidding, Play const & play); // proxy getcard do playera
	void addCard(CardPtr && newCard); // dodaj karte do reki
	void setRole(Role newrole) { role = newrole; }
	Role getRole() { return role; }
	
private:
	
	CardPtr askPlayer(Play const & play, Bidding const & bidding); // popros playera o dodanie karty
	CardPtr askPartner(Play const & play, Bidding const & bidding); // pozwol partnerowi wziac karte
	
	Role role;
	
	IPlayer& player;
	IPlayer& partner;

	Hand hand;	
};


struct EmptyHandException : std::logic_error
{
	explicit EmptyHandException() : std::logic_error("This player's hand is empty.") {}
};

struct NumberOutOfBounds : std::logic_error
{
	explicit NumberOutOfBounds() : std::logic_error("Card number is wrong.") {}
};


} // namespace model

#endif
