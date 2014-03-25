#include <gtest/gtest.h>

#include "Trump.hpp"
#include "Call.hpp"
#include "BiddingConstraint.hpp"

TEST(BiddingConstraintTest, SatisfiesDouble)
{
  BiddingConstraint bidCon;
  bidCon.doublePossible = true;
  bidCon.redoublePossible = false;

  ASSERT_EQ(true, bidCon.satisfies(Call::createPass()));
  ASSERT_EQ(true, bidCon.satisfies(Call::createDouble()));
  ASSERT_EQ(false, bidCon.satisfies(Call::createRedouble()));
}

TEST(BiddingConstraintTest, SatisfiesStandart)
{
  BiddingConstraint bidCon;
  bidCon.doublePossible = false;
  bidCon.redoublePossible = false;
  bidCon.value = 2;
  bidCon.trump = Trump::Clubs;

  ASSERT_EQ(false, bidCon.satisfies(Call::createStandard(1, Trump::NT)));
  ASSERT_EQ(true, bidCon.satisfies(Call::createStandard(5, Trump::Spades)));
}
