#include "Printer.hpp"

const char ui::text::Printer::ranks[] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
#ifdef UNICODE
const std::string ui::text::Printer::suits[] = {"\u2663", "\u2666", "\u2665", "\u2660"};
const std::string ui::text::Printer::trumps[] = {"\u2663", "\u2666", "\u2665", "\u2660", "NT"};
#else
const std::string ui::text::Printer::suits[] = {"C", "D", "H", "S"};
const std::string ui::text::Printer::trumps[] = {"C", "D", "H", "S", "N"};

#endif
const std::string ui::text::Printer::calls[] = {"PASS", "DOUBLE", "REDOUBLE", "STANDARD"};

void ui::text::Printer::print(model::Card const & card, std::string indent)
{
	std::cout << indent 
		<< "["
		<< ui::text::Printer::ranks[static_cast<int>(card.rank)]
		<< ui::text::Printer::suits[static_cast<int>(card.suit)]
		<< "]";
}

void ui::text::Printer::print(model::Trick const & trick, std::string indent)
{
    for(auto& c : trick.getCards()) {
        print(c, indent);
    }
    std::cout << std::endl;
}

void ui::text::Printer::print(model::Hand const & hand, std::string indent)
{
	for(int i=3; i>=0; i--){
		std::cout << indent << ui::text::Printer::suits[i] << ": ";
		for(int j=hand.getCards().size()-1; j>=0; j--){
			model::Card c=hand.getCards()[j];
			if(static_cast<int>(c.suit)==i)
				std::cout << ui::text::Printer::ranks[static_cast<int>(c.rank)] << " ";
		}
		std::cout << std::endl;
	}
}

void ui::text::Printer::print(model::Bidding const & bidding, std::string indent)
{
    for(auto& call : bidding.getHistory()) {
        print(call.second);
    }
	if(bidding.stillGoing()) {
		std::cout	<< indent << "Bidding is going" << std::endl;
		
        print(bidding.getCurrentConstraint());
	} else {

		std::cout	<< indent << "Bidding finished" << std::endl;

		print(bidding.getContract());
	}
}

void ui::text::Printer::print(model::Call const & call, std::string indent)
{
	if(call.type == model::CallType::STANDARD)
		std::cout << indent << call.value << ui::text::Printer::trumps[static_cast<int>(call.trump)];
	else
		std::cout << indent << ui::text::Printer::calls[static_cast<int>(call.type)];
    std::cout << std::endl;
}

void ui::text::Printer::print(model::Contract const & contract, std::string indent){
		std::cout	<< "VALUE: "
			<< contract.value << std::endl
			<< indent << "TRUMP: " << ui::text::Printer::trumps[static_cast<int>(contract.trump)] << std::endl
			<< indent << "MULTIPLIER: "
			<< contract.multiplier << std::endl;
}

void ui::text::Printer::print(model::BiddingConstraint const & constraint, std::string indent){
		std::cout	<< indent << "VALUE: "
			<< constraint.value << std::endl
			<< indent << "TRUMP: "
			<< ui::text::Printer::trumps[static_cast<int>(constraint.trump)] << std::endl;
}
