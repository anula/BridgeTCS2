#include "Application.hpp"
#include "ui/text/Application.hpp"

int main(int argc, char** argv) 
{
    auto application = std::make_shared<Application>();
    auto uiApplication = std::make_shared<ui::text::Application>();
    application->addObserver(uiApplication);
    application->run();
    return 0;
}
