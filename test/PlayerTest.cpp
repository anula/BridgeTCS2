#include <gtest/gtest.h>
#include <string>
#include "../src/Player.hpp"

std::string username = "mistar";

TEST(PlayerTest, testConstructor)
{
	Player p(username);
	ASSERT_EQ(username, p.getName());
}
