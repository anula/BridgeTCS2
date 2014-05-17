#include <gtest/gtest.h>

#include "model/Trump.hpp"
#include "model/Call.hpp"
#include "model/Bidding.hpp"

using namespace model;

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

#define qpass ASSERT_TRUE(bidding.makeCall(Call::createPass()))
#define qdouble ASSERT_TRUE(bidding.makeCall(Call::createDouble()))
#define qredouble ASSERT_TRUE(bidding.makeCall(Call::createRedouble()))
#define qstandard(x,y) ASSERT_TRUE(bidding.makeCall(Call::createStandard(x, y)))

TEST(BiddingTest, NormalBidding)
{
	Bidding bidding;
	qpass;
	qpass;
	qstandard(1, Trump::HEARTS);
	qstandard(1, Trump::NT);
	qstandard(2, Trump::HEARTS);
	qpass;
	qstandard(4, Trump::HEARTS);
	ASSERT_FALSE(bidding.makeCall(Call::createStandard(4, Trump::HEARTS)));
	qdouble;
	qpass;
	qpass;
	qpass;
	ASSERT_FALSE(bidding.stillGoing());
	ASSERT_TRUE(bidding.getDeclarer() == 2);
	ASSERT_TRUE(bidding.getContract().value == 4);
	ASSERT_TRUE(bidding.getContract().trump == Trump::HEARTS);
	ASSERT_TRUE(bidding.getContract().multiplier == 2);
}
