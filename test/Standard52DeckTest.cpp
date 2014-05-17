#include <gtest/gtest.h>
#include "model/Deck.hpp"

using namespace model;

TEST(Standard52Test, SimpleTest)
{
    Standard52Deck deck;
    ASSERT_EQ(deck.count(), 52);
    deck.getCard();
    ASSERT_EQ(deck.count(), 51);
    while(deck.count()>1)
        deck.getCard();
    ASSERT_EQ(deck.count(), 1);
    deck.getCard();
    ASSERT_EQ(deck.count(), 0);
}
