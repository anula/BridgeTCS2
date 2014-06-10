#include <iostream>
#include <sstream>
#include <string>
#include <locale>
#include "ui/text/Player.hpp"
#include "ui/text/Printer.hpp"
#include "model/Trump.hpp"
#include <boost/format.hpp>
#include <boost/algorithm/string/erase.hpp>
#include <boost/algorithm/string.hpp>

namespace ui
{

namespace text
{

model::Card Player::getCard(model::Hand const & hand, model::Bidding const & bidding, model::Play const & play) const 
{
    int cardNumber;
    const std::vector<model::Card> & h = hand.getCards();

    for (;;) {
        std::cout << "Your hand is:  ";
        Printer::print(hand);
        if(play.getDummyHand() != nullptr) {
            std::cout << "Dummy hand is: ";
            Printer::print(*play.getDummyHand());
        }
        Printer::print(bidding);
        for(auto& trick : play.getTricksHistory()) {
            Printer::print(trick);
        }
        std::cout << "Enter card number: ";
        std::cin >> cardNumber;

        if ( cardNumber < 0 || cardNumber >= h.size() ) {
            std::cout << boost::format("%1% is not a valid card number. Hand contains %2% cards.") % cardNumber % h.size() << std::endl;
            continue;   
        }
        break;
    }
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
        
        char type, trump;
        int value;
				std::string line;
				getline(std::cin, line);
				boost::erase_all(line, " ");
				boost::to_lower(line);

				std::istringstream inputStream(line);

        inputStream >> type;
        if(type == 's')
        {
            inputStream >> value >> trump;
            char trumps[] = { 'c', 'd', 'h', 's', 'n' };
            for(int i = 0; i < sizeof(trumps)/sizeof(trumps[0]); i++)
            {
                if(trump == trumps[i]) {
                    call = model::Call::createStandard( value, static_cast<model::Trump>(i));
                    success = true;
                }
            }
        }
        else if(type == 'p') 
        {
            call = model::Call::createPass();
            success = true;
        }
        else if(type == 'd')
        {
            call = model::Call::createDouble();
            success = true;
        }
        else if(type == 'r')
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
