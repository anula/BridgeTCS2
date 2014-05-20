#ifndef UI_TEXT_PRINTER_HPP
#define UI_TEXT_PRINTER_HPP

#include <iostream>
#include "model/Card.hpp"
#include "model/Hand.hpp"
#include "model/Bidding.hpp"
#include "model/Call.hpp"

namespace ui
{
namespace text
{ 

class Printer {
public:
	void print(model::Card const &, std::ostream & = std::cout);
	void print(model::Hand const &, std::ostream & = std::cout);
	void print(model::Bidding const &, std::ostream & = std::cout);
	void print(model::Call const &, std::ostream & = std::cout);
};

}
}

#endif //UI_TEXT_PRINTER_HPP
