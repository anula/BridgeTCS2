#ifndef BIDDING_HPP
#define BIDDING_HPP

#include <vector>
#include <utility>
#include "BiddingConstraint.hpp"
#include "Call.hpp"
#include "Contract.hpp"

namespace model
{

class Bidding
{
public:
	Bidding();
	
	/**
	 * returns false, in case call is illegal
	 * otherwise archives call etc
	 */
	bool makeCall(Call const & call);
	
	/**
	 * returns contract (can be called only when stillGoing() returns false,
	 * otherwise an exception is thrown). 
	 * in case bidding has ended without any non-pass calls,
	 * Contract.value is set to zero!
	 */
	const Contract getContract() const;
	
	/**
	 * returns declarer (with respect to the one beggining the auction)
	 */
	int getDeclarer() const;
	
	const BiddingConstraint getCurrentConstraint() const;
	
	bool stillGoing() const;
	
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
	GPair whoDidLastNonPass; /* who made lastNonPass */
	GPair whoDidLastActual; /* who made lastActual */
	std::vector<std::pair<int, Call>> history;
	
	GPair getPair(int who) const
	{
		if (who % 2 == 0)
			return GPair::NS;
		else
			return GPair::EW;
	}
	
	GPair currentPair() const
	{
		return getPair(whoBidsNow);
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

} // namespace model

#endif // BIDDING_HPP
