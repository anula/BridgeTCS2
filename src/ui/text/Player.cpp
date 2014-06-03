#include <iostream>
#include <string>
#include "ui/text/Player.hpp"
#include "ui/text/Printer.hpp"
#include "model/Trump.hpp"

namespace ui
{

namespace text
{

model::Card Player::getCard(model::Hand const & hand, model::Bidding const & bidding, model::Play const & play) const 
{
    Printer::print(hand);
    Printer::print(bidding);
    for(auto&& trick : play.getTricksHistory()) {
        Printer::print(trick);
    }
    std::cout << "Enter card number:" << std::endl;
    int cardNumber;
    std::cin >> cardNumber;
    const std::vector<model::Card> & h = hand.getCards();
    return h[cardNumber];
}

model::Call Player::getCall(model::Hand const & hand, model::Bidding const & bidding) const 
{
    Printer::print(hand);
    Printer::print(bidding);
    
    // move that later to scanner or something
    std::cout << "Enter P for pass, D for double, R for redouble or S <value> <C/D/H/S/N> for standard call.\n ex. S 1 C" << std::endl;
    std::string type, trump;
    int value;
    std::cin >> type;
    if(type == "S")
    {
        std::cin >> value >> trump;
        std::string trumps[] = { "C", "D", "H", "S", "N" };
        for(int i = 0; i < sizeof(trumps)/sizeof(std::string); i++)
        {
            if(trump == trumps[i])
                return model::Call::createStandard( value, static_cast<model::Trump>(i));
        }
    }
    else if(type == "P") 
    {
        return model::Call::createPass();
    }
    else if(type == "D")
    {
        return model::Call::createDouble();
    }
    else if(type == "R")
    {
        return model::Call::createRedouble();
    }
    throw "something went wrong in ui/text/player";
    // end
}

}

}
