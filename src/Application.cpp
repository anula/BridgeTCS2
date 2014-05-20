#include "Application.hpp"
#include "ui/text/Player.hpp"
#include "model/Game.hpp"

void model::Application::run()
{
    std::cout << "Aplikacja jest uruchamiana..." << std::endl;
    DummyComputerPlayer dummy1;
    DummyComputerPlayer dummy2;
    DummyComputerPlayer dummy3;
    ui::text::Player user;
    sigModified(*this);
    sigModified(*this);
}