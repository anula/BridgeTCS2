#include <gtest/gtest.h>

#include "Trump.hpp"
#include "Call.hpp"
#include "model/BiddingConstraint.hpp"

using namespace model;

TEST(BiddingConstraintTest, SatisfiesDouble)
{
  BiddingConstraint bidCon;
  bidCon.doublePossible = true;
  bidCon.redoublePossible = false;

  ASSERT_TRUE(bidCon.satisfies(Call::createPass()));
  ASSERT_TRUE(bidCon.satisfies(Call::createDouble()));
  ASSERT_FALSE(bidCon.satisfies(Call::createRedouble()));
}

TEST(BiddingConstraintTest, SatisfiesStandart)
{
  BiddingConstraint bidCon;
  bidCon.doublePossible = false;
  bidCon.redoublePossible = false;
  bidCon.value = 2;
  bidCon.trump = Trump::CLUBS;

  ASSERT_FALSE(bidCon.satisfies(Call::createStandard(1, Trump::NT)));
  ASSERT_TRUE(bidCon.satisfies(Call::createStandard(5, Trump::SPADES)));
}
