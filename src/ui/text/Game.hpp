#ifndef UI_TEXT_GAME_HPP
#define UI_TEXT_GAME_HPP

#include <iostream>
#include <string>

#include "model/Game.hpp"

namespace ui
{
namespace text 
{

class Game
{
public:
    
    Game(int n = 0) : indent("") {
        while (n--)
           indent = indent + "\t";
    }

    void notify(model::IGame const & game)
    {
        std::cout << indent << "Zaczynamy robra!" << std::endl;
    }

private:
    std::string indent;
};

}
}

#endif // UI_TEXT_GAME_HPP