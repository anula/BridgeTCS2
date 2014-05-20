#include "ui/text/Bidding.hpp"

void ui::text::Bidding::notify(model::Bidding const & target) 
{
	Printer::print(target);
}

