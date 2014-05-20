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
	static void print(model::Card const &, std::ostream & = std::cout);
	static void print(model::Hand const &, std::ostream & = std::cout);
	static void print(model::Bidding const &, std::ostream & = std::cout);
	static void print(model::Call const &, std::ostream & = std::cout);
	
private:
	static const char ranks[];
	static const std::string suits[];
};

}
}

#endif //UI_TEXT_PRINTER_HPP
