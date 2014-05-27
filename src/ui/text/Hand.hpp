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
	Hand(std::string text) : text(text) {}
	void notify(model::Hand const &);

private:
	std::string text;
};

}
}

#endif //UI_TEXT_HAND_HPP
