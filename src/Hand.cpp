#include "Hand.hpp"

CardPtr Hand::getCard(int index)
{
	if(index > (int)size())
		throw OutOfHandException();
	std::swap((*this)[index], this->back());
	CardPtr ret = std::move(this->back());
	pop_back();
	return ret;
};

void Hand::addCard(CardPtr && card){
	if ( (int)size() == Hand::MAX_SIZE )
		throw FullHandException();
	emplace_back(std::move(card));	
}

const std::vector<CardPtr>& Hand::getCards() const 
{
	return *this;
}

const int Hand::MAX_SIZE = 13;
