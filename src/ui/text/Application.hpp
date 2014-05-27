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
    
    Application(int n = 0) : indent("") {
        while (n--)
           indent = indent + "\t";
    }

    void notify(model::Application const & app) 
    {
        if (app.finished)
            std::cout << indent << "Dziękujemy za grę!" << std::endl;
        else if (app.started)
            std::cout << indent << "Zapraszamy do gry..." << std::endl;
    }
private:
    std::string indent;
};

}
}

#endif // UI_TEXT_APPLICATION_HPP
