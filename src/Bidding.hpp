#ifndef BIDDING_HPP
#define  BIDDING_HPP
class Bidding
{
public:
	Bidding();

	bool makeCall(Call const& call);
	Contract getContract();
	int getDealer();
	BiddingConstraint getCurrentConstraint();
	
private:
	

};
#endif // BIDDING_HPP
