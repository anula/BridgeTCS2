#include "ui/text/Hand.hpp"

void ui::text::Hand::notify(model::Hand const & target) 
{
	std::cout <<	"Hand state: " << std::endl;
	for(auto card : target.getCards())
	{
		std::cout 	<< ranks[static_cast<int>(card.rank)]
					<< "["
					<< suits[static_cast<int>(card.suit)]
					<< "] ";
	}
	std::cout	<< std::endl;
}

const char ui::text::Hand::ranks[] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
const std::string ui::text::Hand::suits[] = {"\u2663", "\u2666", "\u2665", "\u2660"};

