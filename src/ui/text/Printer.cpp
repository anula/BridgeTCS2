#include "Printer.hpp"

const char ui::text::Printer::ranks[] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
const std::string ui::text::Printer::suits[] = {"\u2663", "\u2666", "\u2665", "\u2660"};
const std::string ui::text::Printer::trumps[] = {"\u2663", "\u2666", "\u2665", "\u2660", "NT"};
const std::string ui::text::Printer::calls[] = {"PASS", "DOUBLE", "REDOUBLE", "STANDARD"};

void ui::text::Printer::print(model::Card const & card) 
{
	std::cout << ui::text::Printer::ranks[static_cast<int>(card.rank)]
		<< "["
		<< ui::text::Printer::suits[static_cast<int>(card.suit)]
		<< "]";
}

void ui::text::Printer::print(model::Trick const & trick) 
{
	std::cout << "Hello, World!" << std::endl;
}

void ui::text::Printer::print(model::Hand const & hand)
{
	std::cout << "Hand: " << std::endl;
	for(model::Card c : hand.getCards()) {
		print(c);
		std::cout << ' ';
	}
	std::cout << std::endl;
}

void ui::text::Printer::print(model::Bidding const & bidding)
{
	if(bidding.stillGoing()) {
		std::cout	<< "Bidding is going" << std::endl;
		
		model::BiddingConstraint constraint = bidding.getCurrentConstraint();
		std::cout	<< "VALUE: "
			<< constraint.value << std::endl
			<< "TRUMP: "
			<< ui::text::Printer::trumps[static_cast<int>(constraint.trump)] << std::endl;
	} else {

		std::cout	<< "Bidding finished" << std::endl;

		model::Contract contract = bidding.getContract();
		std::cout	<< "VALUE: "
			<< contract.value << std::endl
			<< "TRUMP: "
			<< ui::text::Printer::trumps[static_cast<int>(contract.trump)] << std::endl
			<< "MULTIPLIER: "
			<< contract.multiplier << std::endl;
	}
}

void ui::text::Printer::print(model::Call const & call)
{
	if(call.type == model::CallType::STANDARD)
		std::cout << call.value << ui::text::Printer::trumps[static_cast<int>(call.trump)];
	else
		std::cout << ui::text::Printer::calls[static_cast<int>(call.type)];
}

