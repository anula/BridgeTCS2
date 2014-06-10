#include "model/Application.hpp"
#include "ui/text/Player.hpp"
#include "model/Game.hpp"
#include "model/SimpleGame.hpp"
#include "ui/text/Game.hpp"

void model::Application::run()
{
    DummyComputerPlayer dummy1;
    DummyComputerPlayer dummy2;
    DummyComputerPlayer dummy3;
    ui::text::Player user;
    game = std::unique_ptr<IGame>(new SimpleGame(dummy1, dummy2, dummy3, user));
	state = STARTED;
    sigModified(*this);
    game->start();
	state = FINISHED;
    sigModified(*this);
}
