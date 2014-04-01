#include "Bidding.hpp"

Bidding::Bidding() : whoBidsNow(0), passCount(0)
{
	lastNonPass = Call::createPass();
	lastActual = Call::createPass();
}

bool Bidding::makeCall(Call const & call)
{
	if (!stillGoing)
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
			whoDidIt = currentPair();
			break;
		case STANDARD: 
			passCount = 0;
			lastNonPass = call;
			lastActual = call;
			whoDidIt = currentPair();
	}
	archive(call);
	next();
}

const Contract Bidding::getContract()
{
	if (stillGoing)
		throw 666;
	
}

const BiddingConstraint Bidding::getCurrentConstraint()
{
	
}

bool Bidding::stillGoing()
{
	/* a bit ugly, I'm sorry */
	if (passCount == 4)
		return false;
	if (passCount == 3 && lastNonPass.type != CallType::PASS)
		return false;
	return true;
}