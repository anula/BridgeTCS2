#ifndef UI_TEXT_PRINTER_HPP
#define UI_TEXT_PRINTER_HPP

#include <iostream>
#include "model/Card.hpp"
#include "model/Hand.hpp"
#include "model/Bidding.hpp"
#include "model/Call.hpp"
#include "model/Trick.hpp"
#include "Hand.hpp"

namespace ui
{
namespace text
{ 

class Printer {
	static const char ranks[];
	static const std::string suits[];
	static const std::string trumps[];
	static const std::string calls[];
public:
	static void print(model::Card const &, std::string indent="");
	static void print(model::Trick const &, std::string indent="");
	static void print(model::Hand const &, std::string indent="");
	static void print(model::Bidding const &, std::string indent="");
	static void print(model::Call const &, std::string indent="");
	static void print(model::Contract const &, std::string indent="");
	static void print(model::BiddingConstraint const &, std::string indent="");
};

}
}

#endif //UI_TEXT_PRINTER_HPP
