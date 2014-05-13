#ifndef BIDDINGCONSTRAINT_HPP
#define BIDDINGCONSTRAINT_HPP

#include "Trump.hpp"
#include "Call.hpp"

namespace model
{

struct BiddingConstraint
{
	int value;
	Trump trump;
	bool doublePossible;
	bool redoublePossible;
	
	bool satisfies(Call const& call) const;
};

} // namespace model

#endif // BIDDINGCONSTRAINT_HPP 
