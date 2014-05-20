#include "Hand.hpp"
#include "Printer.hpp"

const char ui::text::Hand::ranks[] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
const std::string ui::text::Hand::suits[] = {"\u2663", "\u2666", "\u2665", "\u2660"};
const std::string ui::text::Hand::trumps[] = {"\u2663", "\u2666", "\u2665", "\u2660", "NT"};

void ui::text::Hand::notify(model::Hand const & target) 
{
	Printer::print(target);
}

