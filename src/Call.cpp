#include "Call.hpp"

static Call passCall =      {CallType::PASS,     0, 0}
static Call doubleCall =    {CallType::DOUBLE,   0, 0}
static Call redoubleCall =  {CallType::REDOUBLE, 0, 0}
static Call standardCall =  {CallType::STANDARD, 0, 0}

Call Call::createPass() {
	return passCall;
}

Call Call::createDouble() {
	return doubleCall;
}

Call Call::createRedouble() {
	return redoubleCall;
}

Call Call::createStandard(int value, Trump trump) {
	Call result = standardCall;
	result.value = value;
	result.trump = trump;
	return result;
}