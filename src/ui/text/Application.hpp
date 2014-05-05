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
