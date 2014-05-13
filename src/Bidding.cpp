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
	next();
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

const BiddingConstraint Bidding::getCurrentConstraint() const
{
	BiddingConstraint result;
	if (lastNonPass.type == CallType::PASS)
	{
		// nothing happened so far
		result.value = 0; // wtf am i doing
		result.trump = Trump::NT;
		result.doublePossible = false;
		result.redoublePossible = false;
		return result;
	}
	/* ok, lastActual has correct value */
	result.value = lastActual.value;
	result.trump = lastActual.trump;
	/* is double possible? */
	bool temp = true;
	if (lastNonPass.type != CallType::STANDARD)
		temp = false;
	if (whoDidLastNonPass == currentPair())
		temp = false;
	result.doublePossible = temp;
	/* is redouble possible? */
	temp = true;
	if (lastNonPass.type != CallType::DOUBLE)
		temp = false;
	if (whoDidLastNonPass == currentPair())
		temp = false;
	result.redoublePossible = temp;
	
	return result;
	
}

bool Bidding::stillGoing() const
{
	/* a bit ugly, I'm sorry */
	if (passCount == 4)
		return false;
	if (passCount == 3 && lastNonPass.type != CallType::PASS)
		return false;
	return true;
}
