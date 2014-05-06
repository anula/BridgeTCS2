#ifndef UI_TEXT_APPLICATION_HPP
#define UI_TEXT_APPLICATION_HPP

#include <iostream>
#include <string>
#include "ui/Observer.hpp"

namespace ui
{
namespace text 
{

class Application : public ui::Observer<model::Application>
{
public:

    void notify(model::Application const & app) 
    {
        std::cout << "Hello World!" << std::endl;
        std::cout << app.name << std::endl;
    }
};

}
}

#endif // UI_TEXT_APPLICATION_HPP
