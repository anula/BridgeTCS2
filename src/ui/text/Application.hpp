#ifndef UI_TEXT_APPLICATION_HPP
#define UI_TEXT_APPLICATION_HPP

#include <iostream>
#include "ui/Observer.hpp"

namespace ui
{
namespace text 
{

class Application : public ui::Observer< ::Application>
{
public:
    void notify() 
    {
        std::cout << "Hello World!" << std::endl;
    }
};

}
}

#endif // UI_TEXT_APPLICATION_HPP
