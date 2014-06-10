#include <iostream>
#include <string>
#include "ui/text/Player.hpp"
#include "ui/text/Printer.hpp"
#include "model/Trump.hpp"
#include <boost/format.hpp>

namespace ui
{

namespace text
{

model::Card Player::getCard(model::Hand const & hand, model::Bidding const & bidding, model::Play const & play) const 
{
    std::cout << "Your hand is:  ";
    Printer::print(hand);
    if(play.getDummyHand() != nullptr) {
        std::cout << "Dummy hand is: ";
        Printer::print(*play.getDummyHand());
    }
    Printer::print(bidding);
    for(auto&& trick : play.getTricksHistory()) {
        Printer::print(trick);
    }
    std::cout << "Enter card number: ";
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
    model::Call call;
    bool success = false;
    int failCount = 0;
    const int MAX_FAILS = 5;

    do {
        std::string instruction = "Enter P for pass, D for double, R for redouble or S <value> <C/D/H/S/N> for standard call.\n ex. S 1 C";
        if ( failCount > 1 )
        {
            std::cout << boost::format("You have entered a wrong bidding %1% times in a row. After %2%th attempt game will automatically pass.") % failCount % MAX_FAILS
                      << std::endl
                      << instruction
                      << std::endl;
        }
        else
        {
            std::cout << instruction << std::endl;
        }
        
        std::string type, trump;
        int value;
        std::cin >> type;
        if(type == "S")
        {
            std::cin >> value >> trump;
            std::string trumps[] = { "C", "D", "H", "S", "N" };
            for(int i = 0; i < sizeof(trumps)/sizeof(std::string); i++)
            {
                if(trump == trumps[i]) {
                    call = model::Call::createStandard( value, static_cast<model::Trump>(i));
                    success = true;
                }
            }
        }
        else if(type == "P") 
        {
            call = model::Call::createPass();
            success = true;
        }
        else if(type == "D")
        {
            call = model::Call::createDouble();
            success = true;
        }
        else if(type == "R")
        {
            call = model::Call::createRedouble();
            success = true;

        }

        if ( !success )
            failCount += 1;

        if ( failCount == MAX_FAILS ) {
            call = model::Call::createPass();
            success = true;
            std::cout << "You have passed!" << std::endl;
        }
    }
    while ( !success );

    return call;
}

}

}
