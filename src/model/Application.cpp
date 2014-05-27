#include "Application.hpp"
#include "ui/text/Player.hpp"
#include "model/Game.hpp"
#include "model/SimpleGame.hpp"
#include "ui/text/Game.hpp"

void model::Application::run()
{
    started = true;
    sigModified(*this);
    DummyComputerPlayer dummy1;
    DummyComputerPlayer dummy2;
    DummyComputerPlayer dummy3;
    ui::text::Player user;
    SimpleGame game(dummy1, dummy2, dummy3, user);
    ui::text::Game gameView;
    game.sigModified.connect(
        [&gameView] (model::IGame const & game) {
            gameView.notify(game);
        }
    );
    game.start(0);
    finished = true;
    sigModified(*this);
}