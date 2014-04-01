#ifndef CALL_HPP
#define CALL_HPP

#include "Trump.hpp"

enum CallType
{
	PASS,
	DOUBLE,
	REDOUBLE,
	STANDARD
};

struct Call
{
	CallType type;
	int value;
	Trump trump;
	
	static const Call createPass();
	static const Call createRedouble();
	static const Call createDouble();
	static const Call createStandard(int value, Trump trump);
};

#endif // CALL_HPP