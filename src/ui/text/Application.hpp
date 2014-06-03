#ifndef UI_TEXT_APPLICATION_HPP
#define UI_TEXT_APPLICATION_HPP

#include <iostream>
#include <string>

#include "model/Application.hpp"
#include "ui/text/Game.hpp"

namespace ui
{
namespace text 
{

class Application
{
public:
    
    Application(int n = 0) : indent("") , gameView(2){
        while (n--)
           indent = indent + "\t";
    }

    void notify(model::Application const & app);

private:
		std::string indent;
		Game gameView;

};

}
}

#endif // UI_TEXT_APPLICATION_HPP
