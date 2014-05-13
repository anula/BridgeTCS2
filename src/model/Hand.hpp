#ifndef HAND_HPP
#define HAND_HPP

#include "Card.hpp"
#include "Call.hpp"
#include "Role.hpp"
#include <vector>
#include <stdexcept>


namespace model
{

<<<<<<< HEAD:src/Hand.hpp
class Hand : public std::vector<CardPtr> {
=======
class Hand : protected std::vector<Card> 
{
>>>>>>> f1481dcdf67fe45c515fa03ddbc0fa126fa392dc:src/model/Hand.hpp
public:
	Card getCard(int index);
	void addCard(Card card);
	static const int MAX_SIZE = 13;
<<<<<<< HEAD:src/Hand.hpp
	const std::vector<CardPtr>& getCards() const;
    using std::vector<CardPtr>::size;
    using std::vector<CardPtr>::operator[];
=======
	const std::vector<Card>& getCards() const;
>>>>>>> f1481dcdf67fe45c515fa03ddbc0fa126fa392dc:src/model/Hand.hpp
};


struct FullHandException : std::logic_error
{
	explicit FullHandException() : std::logic_error("This player's hand is full.") {}
};

struct OutOfHandException : std::logic_error
{
	explicit OutOfHandException() : std::logic_error("This index is out of player's hand.") {}
};

} // namespace model

#endif
