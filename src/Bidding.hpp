#ifndef BIDDING_HPP
#define  BIDDING_HPP

#include <vector>
#include <utility>


class Bidding
{
public:
	Bidding();
	
	bool makeCall(Call const& call);
	
	Contract getContract();
	
	BiddingConstraint getCurrentConstraint();
	
	bool stillGoing();
	
private:
	int whoBidsNow; /* 0, 1, 2, 3 */
	int passCount; /* how many consecutive passes at the end */
	Call lastNonPass; /* last non-pass call */
	std::vector<std::pair<int, Call>> history;
	
	void next() 
	{
		++whoBidsNow;
		whoBidsNow %= 4;
	}
	
	void archive(Call const & call) 
	{
		history.push_back(std::make_pair(whoBidsNow, call));
	}
	
	
	
}
#endif // BIDDING_HPP
