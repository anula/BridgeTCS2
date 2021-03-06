#include "model/BiddingConstraint.hpp"

bool model::BiddingConstraint::satisfies(Call const & call) const 
{
	switch (call.type) 
	{
		case PASS:
			return true;
			
		case DOUBLE:
			return doublePossible;
			
		case REDOUBLE:
			return redoublePossible;
			
		case STANDARD:
			if (call.value > 7)
				return false;
			if (call.value > value)
				return true;
			if (call.value == value && call.trump > trump)
				return true;
	}
	return false;
}
