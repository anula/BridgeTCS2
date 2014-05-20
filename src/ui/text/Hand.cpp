#include "ui/text/Hand.hpp"

void ui::text::Hand::notify(model::Hand const & target) 
{
	Printer::print(target);
}

