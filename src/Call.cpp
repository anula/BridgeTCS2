#include "Call.hpp"

using namespace model;

static Call passCall =      {CallType::PASS};
static Call doubleCall =    {CallType::DOUBLE};
static Call redoubleCall =  {CallType::REDOUBLE};
static Call standardCall =  {CallType::STANDARD};

const Call Call::createPass() {
	return passCall;
}

const Call Call::createDouble() {
	return doubleCall;
}

const Call Call::createRedouble() {
	return redoubleCall;
}

const Call Call::createStandard(int value, Trump trump) {
	Call result = standardCall;
	result.value = value;
	result.trump = trump;
	return result;
}
