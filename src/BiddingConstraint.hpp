#ifndef BIDDINGCONSTRAINT_HPP
#define BIDDINGCONSTRAINT_HPP

#include "Trump.hpp"

struct BiddingConstraint
{
	int value;
	Trump trump;
	bool doublePossible;
	bool redoublePossible;
	
	bool satisfies(Call const& call) const;
};
#endif // BIDDINGCONSTRAINT_HPP 
