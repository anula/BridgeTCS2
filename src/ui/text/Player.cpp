
#include <iostream>
#include "ui/text/Player.hpp"
#include "ui/text/Printer.hpp"

namespace ui
{

namespace text
{

model::Card Player::getCard(model::Hand const & hand, model::Bidding const & bidding, model::Play const & play)
{
    Printer::print(hand);
    int cardNumber;
    std::cin >> cardNumber;
    return hand[cardNumber];
}

model::Call Player::getCall(model::Hand const & hand, model::Bidding const & bidding)
{
    Printer::print(hand);
    Printer::print(bidding);
    return model::Call().createPass();
}

}

}
