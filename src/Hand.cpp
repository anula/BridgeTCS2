#include <Hand.hpp>

CardPtr Hand::getCard(int index)
{
	std::swap((*this)[index], this->back());
	CardPtr ret = this->back();
	pop_back();
	return ret;
};

void Hand::addCard(CardPtr && card){
	if ( size() == Hand::MAX_SIZE )
		throw FullHandException();
	push_back(card);	
}

const int Hand::MAX_SIZE = 13;
