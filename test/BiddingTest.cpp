#include <gtest/gtest.h>

#include "Trump.hpp"
#include "Call.hpp"
#include "Bidding.hpp"

TEST(BiddingTest, CanWePass)
{
	Bidding bidding;
	ASSERT_TRUE(bidding.makeCall(Call::createPass()));
	
}

TEST(BiddingTest, CanWeBid)
{
	Bidding bidding;
	ASSERT_TRUE(bidding.makeCall(Call::createPass()));
	ASSERT_TRUE(bidding.makeCall(Call::createPass()));
	ASSERT_TRUE(bidding.makeCall(Call::createPass()));
	ASSERT_TRUE(bidding.makeCall(Call::createStandard(2, Trump::CLUBS)));
	ASSERT_FALSE(bidding.makeCall(Call::createStandard(1, Trump::NT)));
	ASSERT_TRUE(bidding.makeCall(Call::createDouble()));
	ASSERT_TRUE(bidding.makeCall(Call::createPass()));
	ASSERT_TRUE(bidding.makeCall(Call::createPass()));
	ASSERT_TRUE(bidding.makeCall(Call::createRedouble()));
	ASSERT_TRUE(bidding.makeCall(Call::createPass()));
	ASSERT_TRUE(bidding.makeCall(Call::createPass()));
	ASSERT_TRUE(bidding.makeCall(Call::createPass()));
	ASSERT_FALSE(bidding.stillGoing());

}

