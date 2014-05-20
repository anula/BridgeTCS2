#include "Application.hpp"

void model::Application::run()
{
    std::cout << "Aplikacja jest uruchamiana..." << std::endl;
    DummyComputerPlayer dummy1;
    DummyComputerPlayer dummy2;
    DummyComputerPlayer dummy3;
    //Player user = Player("Zdzisław");
    sigModified(*this);
}