#include <gtest/gtest.h>

#include "Trump.hpp"
#include "Call.hpp"
#include "BiddingConstraint.hpp"

TEST(BiddingConstraintTest, SatisfiesDouble)
{
  BiddingConstraintTest bidCon;
  bidCon.ifDouble = true;
  bidCon.ifRedouble = false;

  ASSERT_EQ(true, bidCon.satisfies(CallFactory.createPass()));
  ASSERT_EQ(true, bidCon.satisfies(CallFactory.createDouble()));
  ASSERT_EQ(false, bidCon.satisfies(CallFactory.createRedouble()));
  ASSERT_EQ(false, bidCon.satisfies(CallFactory.createStandard(1, Trump.NT)));
}
