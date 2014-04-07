#include <gtest/gtest.h>
#include "../src/PlayState.h"

TEST(PlayStateTest, Constructor) {
	PlayState playState(Trump.SPADES, 1);
	ASSERT_EQ(Trump.SPADES, playState.getTrump());
	ASSERT_EQ(1, playState.getBeginningPlayer());
	ASSERT_EQ(1, playState.getPrimaryBeginningPlayer());
	ASSERT_EQ(0, playState.trickCount());
}

TEST(PlayStateTest, Setters) {
	PlayState playState(Trump.HEARTS, 0);
	playState.incrementPlayerScore(2);
	playState.setBeginningPlayer(2);
	ASSERT_EQ(2, playState.getBeginningPlayer());
	ASSERT_EQ(0, playState.getPrimaryBeginningPlayer());
	ASSERT_EQ(1, playState.trickCount());
	ASSERT_EQ(1, playState.getScoreOf(2));
}
