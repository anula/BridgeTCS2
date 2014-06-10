#include <iostream>

#include "SimpleGame.hpp"
#include "model/Deal.hpp"
#include "ui/text/Deal.hpp"

void SimpleGame::start(int starter) 
{
	sigModified(*this);
	Deal oneAndOnly(arbiters, starter);
	ui::text::Deal dealView(3);
	oneAndOnly.sigModified.connect(
        [&dealView] (model::Deal const & deal) {
            dealView.notify(deal);
        }
    );
	oneAndOnly.perform();
	result = oneAndOnly.getDealResult();
}
