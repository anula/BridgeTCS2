#ifndef UI_TEXT_HAND_HPP
#define UI_TEXT_HAND_HPP

#include <iostream>
#include "model/Hand.hpp"
#include "model/Card.hpp"

namespace ui
{
namespace text
{
	
class Hand
{
public:
	void notify(model::Hand const &);
	static const char ranks[];// = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
	static const std::string suits[];// = {"\u2663", "\u2666", "\u2665", "\u2660"};
	static const std::string trumps[];
};

}
}

#endif //UI_TEXT_HAND_HPP
