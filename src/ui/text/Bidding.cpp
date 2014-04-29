#inlude <iostream>

namespace ui::text
{
	
class Bidding : Observer<::Bidding>
{
public:
	void notify() 
	{
		if(target->stillGoing()) {
			
			std::cout	<< "Bidding is going" << std::endl;
			
			// todo
		
		} else {
		
			std::cout	<< "Bidding finished" << std::endl;
			
			Contract contract = target->getContract();
			std::cout	<< "VALUE: "
						<< contract.value << std::endl
						<< "TRUMP: "
						<< contract.trump << std::endl
						<< "MULTIPLIER: "
						<< contract.multiplier << std::endl;
		}
	}


}
	
	
	
}
