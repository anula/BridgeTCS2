#include "Deal.hpp"

void ui::text::Deal::notify(model::Deal const & deal)
{
	Printer::print(deal);
}


ui::text::Deal::Deal(int n = 0) : indent("") {
    while (n--)
       indent = indent + "\t";
}


