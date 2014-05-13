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
	static const std::string trumps[];
	
public:
	void notify(model::Bidding const &);
	
};

}
}

#endif //UI_TEXT_BIDDING_HPP
