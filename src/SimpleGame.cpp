#include <iostream>

#include "SimpleGame.hpp"
#include "model/Deal.hpp"

void SimpleGame::start(int starter) 
{
	Deal oneAndOnly(arbiters, starter);
	oneAndOnly.perform();
	DealResult results = oneAndOnly.getDealResult();
	std::cout << "Gratulacje, udalo sie zgarnac " << results.tricksCollected << " lew!" << std::endl;
}

