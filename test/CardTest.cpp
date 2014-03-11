#include <gtest/gtest.h>
#include "Card.hpp"
using namespace std;


TEST(CardTest, Constructor){
    Card card(Rank::ACE, Suit::HEARTS);
    ASSERT_EQ(card.suit, Suit::HEARTS);
    ASSERT_EQ(card.rank, Rank::ACE);
}
