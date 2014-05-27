#ifndef UI_TEXT_DEAL_HPP
#define UI_TEXT_DEAL_HPP

#include <iostream>
#include <string>

#include "model/Deal.hpp"

namespace ui
{
namespace text 
{

class Deal
{
public:
    
    Deal(int n = 0) : indent("") {
        while (n--)
           indent = indent + "\t";
    }

    void notify(model::Deal const & deal)
    {

    }
private:
    std::string indent;
};

}
}

#endif // UI_TEXT_DEAL_HPP