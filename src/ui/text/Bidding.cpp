#include "ui/text/Bidding.hpp"

void ui::text::Bidding::notify(model::Bidding const & bidding) 
{
	std::cout << text << std::endl; 
	Printer::print(bidding);
}

