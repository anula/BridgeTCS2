#include <gtest/gtest.h>
#include <string>

TEST(PlayerTest, konstruktor)
{
	std::string username = "mistar";
	Player p(username);
	ASSERT_EQ(username, p.getName());
}
