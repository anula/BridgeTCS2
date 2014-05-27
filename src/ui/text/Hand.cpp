#include "Hand.hpp"
#include "Printer.hpp"

void ui::text::Hand::notify(model::Hand const & hand) 
{
	std::cout << text << std::endl;
	Printer::print(hand);
}

