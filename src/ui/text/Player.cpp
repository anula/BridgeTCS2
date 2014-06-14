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

const char Player::ranks[] = {'2','3','4','5','6','7','8','9','t','j','q','k','a'};
const char Player::suits[] = {'c', 'd', 'h', 's'};

model::Card Player::strategy(bool fromDummy, model::Hand const & playerHand, model::Bidding const & bidding, model::Play const & play) 
{
    model::Hand const & hand = fromDummy ? *play.getDummyHand() : playerHand;
    int cardNumber;
    const std::vector<model::Card> & h = hand.getCards();
    for (;;) {
        std::cout << "Your hand is:  ";
        Printer::print(playerHand);
        if(play.getDummyHand() != nullptr) {
            std::cout << "Dummy hand is: ";
            Printer::print(*play.getDummyHand());
        }
        Printer::print(bidding);
        for(auto& trick : play.getTricksHistory()) {
            Printer::print(trick);
        }
        std::cout << "Enter card (eg. K D): ";
        std::string line;
        if (!getline(std::cin, line)) {
            throw new std::runtime_error("Game interrupted");
        }
        boost::erase_all(line, " ");
        boost::to_lower(line);

        std::istringstream inputStream(line);

        char value,trump;
        inputStream >> value >> trump;

        cardNumber = -1;
        for (unsigned int i = 0; i < h.size(); i++) {
            auto const & card = h[i];
            if (ranks[static_cast<int>(card.rank)] == value
                    && suits[static_cast<int>(card.suit)] == trump) {
                cardNumber = i;
            }
        }
        if (cardNumber == -1) {
            std::cout << "There is no such card in the hand." << std::endl;
            continue;
        }

        break;
    }
    if(!fromDummy)
    {
        myHand = hand;
        myHand.getCard(cardNumber);
    }
    return h[cardNumber];
}

model::Card Player::getDummyCard(model::Hand const & hand, model::Bidding const & bidding, model::Play const & play)  
{
	std::cout << "Play card from dummy." << std::endl;
	return strategy(true, myHand, bidding, play);
}

model::Card Player::getCard(model::Hand const & hand, model::Bidding const & bidding, model::Play const & play) 
{
	std::cout << "Play card from your hand." << std::endl;
	return strategy(false, hand, bidding, play);
}

model::Call Player::getCall(model::Hand const & hand, model::Bidding const & bidding)
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
		if (!getline(std::cin, line)) 
		{
            throw new std::runtime_error("Game interrupted");
		}
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
