#include "Hand.hpp"

using namespace model;

Card Hand::getCard(int index)
{
	if(index > (int)size() || index < 0)
		throw NumberOutOfBounds();
	std::swap((*this)[index], this->back());
	Card ret = this->back();
	pop_back();
	return ret;
};

void Hand::addCard(Card card){
	if ( (int)size() == Hand::MAX_SIZE )
		throw FullHandException();
	push_back(card);	
}

const std::vector<Card>& Hand::getCards() const 
{
	return *this;
}
	
