#include <gtest/gtest.h>
#include "Card.hpp"
using namespace std;


TEST(CardTest, Constructor){
    Card card(ACE, HEARTS);
    ASSERT_EQ(card.suit, HEARTS);
    ASSERT_EQ(card.rank, ACE);
}
