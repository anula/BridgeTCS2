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
public:
	static void print(model::Card const &);
	static void print(model::Trick const &);
	static void print(model::Hand const &);
	static void print(model::Bidding const &);
	static void print(model::Call const &);
};

}
}

#endif //UI_TEXT_PRINTER_HPP
