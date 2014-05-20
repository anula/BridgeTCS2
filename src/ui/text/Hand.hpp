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
public:
	void notify(model::Hand const &);
};

}
}

#endif //UI_TEXT_HAND_HPP
