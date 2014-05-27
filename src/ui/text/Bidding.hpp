#ifndef UI_TEXT_BIDDING_HPP
#define UI_TEXT_BIDDING_HPP

#include <iostream>
#include "model/Bidding.hpp"

namespace ui
{
namespace text
{
	
class Bidding
{
public:
	Bidding(std::string text) : text(text) {}
	void notify(model::Bidding const &);
	
};

}
}

#endif //UI_TEXT_BIDDING_HPP
