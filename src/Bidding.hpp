#ifndef BIDDING_HPP
#define  BIDDING_HPP

#include "Call.hpp"

class Bidding
{
public:
	Bidding();

	bool makeCall(Call const& call);
	Contract getContract();
	int getDealer();
	BiddingConstraint

};
#endif // BIDDING_HPP
