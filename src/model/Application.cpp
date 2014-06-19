#include "model/Application.hpp"
#include "ui/text/Player.hpp"
#include "model/Game.hpp"
#include "model/SimpleGame.hpp"
#include "ui/text/Game.hpp"

void model::Application::run()
{
    while(true) {
        DummyComputerPlayer dummy1;
        DummyComputerPlayer dummy2;
        DummyComputerPlayer dummy3;
        ui::text::Player user;
        game.reset(new SimpleGame(dummy1, dummy2, dummy3, user));
        state = STARTED;
        sigModified(*this);
        game->start();
        state = FINISHED;
        sigModified(*this);
    }
}
