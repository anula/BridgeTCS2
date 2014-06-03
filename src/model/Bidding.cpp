#include "Bidding.hpp"

using namespace model;

Bidding::Bidding() 
		: whoBidsNow(0), passCount(0), 
		lastNonPass(Call::createPass()), 
		lastActual(Call::createPass()) {}

bool Bidding::makeCall(Call const & call)
{
	if (!stillGoing())
		throw 666;
	if (!getCurrentConstraint().satisfies(call))
		return false;
	/* all right, call is legal */
	switch (call.type) {
		case PASS: // nothing interesting
			++passCount;
			break;
		case DOUBLE:
		case REDOUBLE: // these cases don't differ
			passCount = 0;
			lastNonPass = call;
			whoDidLastNonPass = currentPair();
			break;
		case STANDARD: 
			passCount = 0;
			lastNonPass = call;
			whoDidLastNonPass = currentPair();
			lastActual = call;
			whoDidLastActual = currentPair();
	}
	archive(call);
	advanceBidder();
	updateCurrentConstraint();
	return true;
}

const Contract Bidding::getContract() const
{
	if (stillGoing())
		throw 666;
	Contract result;
	if (lastNonPass.type == CallType::PASS) 
	{
		// nothing happened
		result.value = 0;
		result.trump = Trump::NT;
		result.multiplier = 0;
		return result;
	}
	result.value = lastActual.value;
	result.trump = lastActual.trump;
	result.multiplier = 1;
	if (lastNonPass.type == CallType::DOUBLE)
		result.multiplier = 2;
	if (lastNonPass.type == CallType::REDOUBLE)
		result.multiplier = 4;
	return result;
	
}

int Bidding::getDeclarer() const 
{
	if (stillGoing())
		throw 666;
	if (lastNonPass.type == CallType::PASS)
		return 666; /* don't do it */
	for (std::pair<int, Call> c : history) {
		if (c.second.trump == lastActual.trump
				&& getPair(c.first) == whoDidLastActual)
			return c.first;
	}
}

const BiddingConstraint & Bidding::getCurrentConstraint() const 
{
	return currentConstraint;
}


void Bidding::updateCurrentConstraint()
{
	currentConstraint = BiddingConstraint();
	if (lastNonPass.type == CallType::PASS)
	{
		// nothing happened so far
		currentConstraint.value = 0; // wtf am i doing
		currentConstraint.trump = Trump::NT;
		currentConstraint.doublePossible = false;
		currentConstraint.redoublePossible = false;
		return;
	}
	/* ok, lastActual has correct value */
	currentConstraint.value = lastActual.value;
	currentConstraint.trump = lastActual.trump;
	/* is double possible? */
	currentConstraint.doublePossible = (lastNonPass.type == CallType::STANDARD && whoDidLastNonPass != currentPair());
	/* is redouble possible? */
	currentConstraint.redoublePossible = (lastNonPass.type == CallType::DOUBLE && whoDidLastNonPass != currentPair());
}

bool Bidding::stillGoing() const
{
	if (passCount == 4)
		return false;
	if (passCount == 3 && lastNonPass.type != CallType::PASS)
		return false;
	return true;
}

std::vector<std::pair<int, Call>> const& Bidding::getHistory() const {
    return history;
}
