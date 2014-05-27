
#include <iostream>
#include "ui/text/Player.hpp"
#include "ui/text/Printer.hpp"

namespace ui
{

namespace text
{

model::Card Player::getCard(model::Hand & hand, model::Bidding const & bidding, model::Play const & play) const 
{
    Printer::print(hand);
    int cardNumber;
    std::cin >> cardNumber;
    return hand.getCard(cardNumber);
}

model::Call Player::getCall(model::Hand const & hand, model::Bidding const & bidding) const 
{
    Printer::print(hand);
    Printer::print(bidding);
    return model::Call().createPass();
}

}

}
