#include "Hand.hpp"
#include <algorithm>

using namespace model;

Card Hand::getCard(int index)
{
	if(index >= (int)size() || index < 0)
		throw NumberOutOfBounds();
	auto toRemove = begin() + index;
	Card ret = *toRemove;
	erase(toRemove);
	return ret;
};

void Hand::addCard(Card card){
	if ( (int)size() >= Hand::MAX_SIZE )
		throw FullHandException();
	push_back(card);	
	
	if( (int)size()==MAX_SIZE) 
		std::sort(begin(), end(), CardComparator());
}

const std::vector<Card>& Hand::getCards() const 
{
	return *this;
}
	
