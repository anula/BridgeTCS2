#ifndef UI_TEXT_PLAY_HPP
#define UI_TEXT_PLAY_HPP

#include <iostream>
#include "model/Play.hpp"

namespace ui
{
namespace text
{
	
class Play
{
public:
	Play(std::string text="") : text(text) {}
	void notify(model::Play const &);

private:
	std::string text;
};

}
}

#endif //UI_TEXT_PLAY_HPP
