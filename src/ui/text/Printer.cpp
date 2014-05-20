#include "Printer.hpp"

const char ui::text::Hand::ranks[] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
const std::string ui::text::Hand::suits[] = {"\u2663", "\u2666", "\u2665", "\u2660"};

void ui::text::Printer::print(model::Card const & card, std::ostream & out = std::cout) 
{
	out << ui::text::Hand::ranks[static_cast<int>(card.rank)]
		<< "["
		<< ui::text::Hand::suits[static_cast<int>(card.suit)]
		<< "]";
}

void ui::text::Printer::print(model::Trick const & trick, std::ostream & out = std::cout) 
{
	out << "Hello, World!" << std::endl;
}

void ui::text::Printer::print(model::Hand const & hand, std::ostream & out = std::cout)
{
	for(Card c : hand.getCards()) {
		print(c, out);
		out << ' ';
	}
}

void ui::text::Printer::print(model::Bidding const & bidding, std::ostream & out = std::cout)
{
	if(target.stillGoing()) {

		out	<< "Bidding is going" << std::endl;
		
		model::BiddingConstraint constraint = target.getCurrentConstraint();
		out	<< "VALUE: "
			<< constraint.value << std::endl
			<< "TRUMP: "
			<< trumps[static_cast<int>(constraint.trump)] << std::endl;
	} else {

		out	<< "Bidding finished" << std::endl;

		model::Contract contract = target.getContract();
		out	<< "VALUE: "
			<< contract.value << std::endl
			<< "TRUMP: "
			<< trumps[static_cast<int>(contract.trump)] << std::endl
			<< "MULTIPLIER: "
			<< contract.multiplier << std::endl;
	}
}

