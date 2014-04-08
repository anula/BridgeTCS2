#ifndef BIDDING_HPP
#define BIDDING_HPP

#include <vector>
#include <utility>
#include "BiddingConstraint.hpp"
#include "Call.hpp"
#include "Contract.hpp"

class Bidding
{
public:
	Bidding();
	
	/**
	 * returns false, in case call is illegal
	 * otherwise archives call etc
	 */
	bool makeCall(Call const & call);
	
	const Contract getContract();
	
	const BiddingConstraint getCurrentConstraint();
	
	bool stillGoing();
	
private:
	
	/**
	 * little enum just for conveinience
	 * 
	 */
	enum GPair 
	{
		NS,   // 0 and 2
		EW   // 1 and 3
	};
	
	int whoBidsNow; /* 0, 1, 2, 3 */
	int passCount; /* how many consecutive passes at the end */
	Call lastNonPass; /* last non-pass call */
	/* ^^^^ convention: if there wasn't any non-pass calls,
	 * this field is set to pass */
	Call lastActual; /* not pass, not double and not redouble */
	GPair whoDidIt; /* who made lastNonPass */
	std::vector<std::pair<int, Call>> history;
	
	GPair currentPair()
	{
		if (whoBidsNow % 2 == 0)
			return GPair::NS;
		else
			return GPair::EW;
	}
	
	void next() 
	{
		++whoBidsNow;
		whoBidsNow %= 4;
	}
	
	/**
	 * warining:
	 * ALWAYS execute this method before "next"
	 * 
	 */
	void archive(Call const & call) 
	{
		history.push_back(std::make_pair(whoBidsNow, call));
	}
	
};
#endif // BIDDING_HPP
