#include <iostream>
#include "ui/Observer.hpp"

namespace ui::text
{

	
class Bidding : Observer<::Bidding>
{

	static const std::string trumps[] = {"C","D","H","S","NT"};
	
public:
	void notify(const ::Bidding & target) 
	{
		if(target.stillGoing()) {
			
			std::cout	<< "Bidding is going" << std::endl;
			
			BiddingConstraint constraint = target.getConstraint();
			std::cout	<< "VALUE: "
						<< constraint.value << std::endl
						<< "TRUMP: "
						<< trumps[constraint.trump] << std::endl
		
		} else {
		
			std::cout	<< "Bidding finished" << std::endl;
			
			Contract contract = target.getContract();
			std::cout	<< "VALUE: "
						<< contract.value << std::endl
						<< "TRUMP: "
						<< trumps[contract.trump] << std::endl
						<< "MULTIPLIER: "
						<< contract.multiplier << std::endl;
		}
	}


}
	
	
	
}
