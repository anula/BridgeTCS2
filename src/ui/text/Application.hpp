#ifndef UI_TEXT_APPLICATION_HPP
#define UI_TEXT_APPLICATION_HPP

#include <iostream>
#include <string>

#include "model/Application.hpp"

namespace ui
{
namespace text 
{

class Application
{
public:

    void notify(model::Application const & app) 
    {
        if (app.finished)
            std::cout << "Dziękujemy za grę!" << std::endl;
        else if (app.started)
            std::cout << "Zapraszamy do gry..." << std::endl;
    }
};

}
}

#endif // UI_TEXT_APPLICATION_HPP
