#ifndef UI_TEXT_HAND_HPP
#define UI_TEXT_HAND_HPP

#include <iostream>
#include "model/Hand.hpp"
#include "Card.hpp"

namespace ui
{
namespace text
{
	
class Hand
{
	static const char ranks[];
	static const std::string suits[];

public:
	void notify(model::Hand const &);
};

// const char Hand::ranks[] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
// const std::string Hand::suits[] = {"\u2663", "\u2666", "\u2665", "\u2660"};
	
}
}

#endif //UI_TEXT_HAND_HPP
