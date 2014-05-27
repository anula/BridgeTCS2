#ifndef UI_TEXT_GAME_HPP
#define UI_TEXT_GAME_HPP

#include <iostream>
#include <string>

#include "../../model/Game.hpp"

namespace ui
{
namespace text 
{

class Game
{
public:

    void notify(model::IGame const & game)
    {
        std::cout << "Zaczynamy robra!" << std::endl;
    }
};

}
}

#endif // UI_TEXT_GAME_HPP