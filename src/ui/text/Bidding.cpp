#include "ui/text/Bidding.hpp"

void ui::text::Bidding::notify(model::Bidding const & target) 
{
	if(target.stillGoing()) {
		
		std::cout	<< "Bidding is going" << std::endl;
		
		BiddingConstraint constraint = target.getConstraint();
		std::cout	<< "VALUE: "
					<< constraint.value << std::endl
					<< "TRUMP: "
					<< trumps[static_cast<int>(constraint.trump)] << std::endl
	
	} else {
	
		std::cout	<< "Bidding finished" << std::endl;
		
		Contract contract = target.getContract();
		std::cout	<< "VALUE: "
					<< contract.value << std::endl
					<< "TRUMP: "
					<< trumps[static_cast<int>(contract.trump)] << std::endl
					<< "MULTIPLIER: "
					<< contract.multiplier << std::endl;
	}
}

const std::string ui::text::Bidding::trumps[] = {"C","D","H","S","NT"};
