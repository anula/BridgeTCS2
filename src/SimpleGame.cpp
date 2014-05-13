#include <iostream>

#include "SimpleGame.hpp"
#include "Deal.hpp"

SimpleGame::start(int starter) 
{
	Deal oneAndOnly(arbiters, starter);
	oneAndOnly.perform();
	DealResult results = oneAndOnly.getDealResult();
	std::cout << "Gratulacje, udalo sie zgarnac " << results.tricksCollected << " lew!" << std::endl;
}