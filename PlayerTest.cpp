#include <gtest/gtest.h>
#include <string>
#include "Player.cpp"

TEST(PlayerTest, konstruktor)
{
	std::string username = "mistar";
	Player p(username);
	ASSERT_EQ(username, p.getName());
}
