#ifndef TRUMP_HPP
#define TRUMP_HPP
#include "Card.hpp"
namespace model
{

enum class Trump
{
	CLUBS,
	DIAMONDS,
	HEARTS,
	SPADES,
	NT
};

inline bool operator==(const Suit& s, const Trump& t){
	return static_cast<int>(s)==static_cast<int>(t);
}


} // namespace model

#endif // TRUMP_HPP
