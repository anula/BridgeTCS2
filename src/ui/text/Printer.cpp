#include "Printer.hpp"

void ui::text::Printer::print(model::Card const & card) 
{
	std::cout << ui::text::Hand::ranks[static_cast<int>(card.rank)]
		<< "["
		<< ui::text::Hand::suits[static_cast<int>(card.suit)]
		<< "]";
}

void ui::text::Printer::print(model::Trick const & trick) 
{
	std::cout << "Hello, World!" << std::endl;
}

void ui::text::Printer::print(model::Hand const & hand)
{
	for(model::Card c : hand.getCards()) {
		print(c);
		std::cout << ' ';
	}
}

void ui::text::Printer::print(model::Bidding const & bidding)
{
	if(bidding.stillGoing()) {
		std::cout	<< "Bidding is going" << std::endl;
		
		model::BiddingConstraint constraint = bidding.getCurrentConstraint();
		std::cout	<< "VALUE: "
			<< constraint.value << std::endl
			<< "TRUMP: "
			<< ui::text::Hand::trumps[static_cast<int>(constraint.trump)] << std::endl;
	} else {

		std::cout	<< "Bidding finished" << std::endl;

		model::Contract contract = bidding.getContract();
		std::cout	<< "VALUE: "
			<< contract.value << std::endl
			<< "TRUMP: "
			<< ui::text::Hand::trumps[static_cast<int>(contract.trump)] << std::endl
			<< "MULTIPLIER: "
			<< contract.multiplier << std::endl;
	}
}

