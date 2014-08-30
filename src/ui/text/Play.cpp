#include "ui/text/Play.hpp"

void ui::text::Play::notify(model::Play const & play)
{
	if(play.state == model::Play::State::NEWWINNER){
		std::cout << "Player " << play.getBeginningPlayer() << " won the trick." << std::endl;
		std::cout << std::endl;
	}
}
