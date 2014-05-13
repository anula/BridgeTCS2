#ifndef UI_TEXT_APPLICATION_HPP
#define UI_TEXT_APPLICATION_HPP

#include <iostream>
#include <string>

namespace ui
{
namespace text 
{

class Application
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
