#include <iostream>
#include "ui/Observer.hpp"

namespace ui::text
{
	
class Hand : Observer<::Hand>
{
	static const std::string ranks[] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
	static const std::string suits[] = {"C","D","H","S"};

public:
	void notify(const ::Hand & target) 
	{
		std::cout <<	"Hand state:" << std::endl;
		for(CardPtr card : target.getCards())
		{
			std::cout 	<< ranks[card->rank]
						<< "["
						<< suits[card->suit]
						<< "] ";
		}
		std::cout	<< std::endl;
	}
}

}
