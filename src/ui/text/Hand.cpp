#inlude <iostream>

namespace ui::text
{
	
class Hand : Observer<::Hand>
{
public:
	void notify(const Hand & target) 
	{
		std::cout <<	"Hand state:" << std::endl;
		for(CardPtr card : target.getCards())
		{
			std::cout 	<< card->rank
						<< "["
						<< card->suit
						<< "]"
						<< std::endl;
		}
	}
}

}
