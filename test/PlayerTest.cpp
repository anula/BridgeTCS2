#include <gtest/gtest.h>
#include <string>
#include "../src/Player.hpp"

std::string username = "mistar";

TEST(PlayerTest, testConstructor)
{
	Player p(username);
	ASSERT_EQ(username, p.getName());
}

TEST(PlayerTest, testRaisesExceptionWhenEmptyHand)
{
	Player p(username);
	ASSERT_THROW(p.getCard(0), EmptyHandException);
}


TEST(PlayerTest, testRaisesExceptionWhenFullHand)
{
	Player p(username);
	Card c(Rank::TWO, Suit::HEARTS);
	ASSERT_THROW(p.addCard(c), FullHandException);
}

