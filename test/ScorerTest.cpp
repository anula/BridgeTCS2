#include <gtest/gtest.h>

#include "model/Scorer.hpp"
#include "model/Score.hpp"
#include "model/Deal.hpp"

#include <iostream>

using namespace model;

void contract_points_test(int expected, Trump trump, int value, int multiplier, int collected)
{
	Scorer scorer;
	DealResult result;
	Contract contract;

	contract.trump = trump;
	contract.value = value;
	contract.multiplier = multiplier;

	result.tricksCollected = collected;
	result.contract = contract;

	ASSERT_EQ(0, scorer.getDealScores().size());	
	scorer.update(result);
	ASSERT_EQ(1, scorer.getDealScores().size());	

	DealScore const & score = scorer.getDealScores().back();

	ASSERT_EQ(expected, score.contractPoints);
}

TEST(ScorerTest, TestContractPointsNoTrump)
{
	contract_points_test(40, Trump::NT, 1, 1, 1);
	contract_points_test(80, Trump::NT, 1, 2, 1);
	contract_points_test(160, Trump::NT, 1, 4, 1);

	contract_points_test(70, Trump::NT, 2, 1, 2);
	contract_points_test(140, Trump::NT, 2, 2, 2);
	contract_points_test(280, Trump::NT, 2, 4, 2);

	contract_points_test(0, Trump::NT, 2, 1, 1);
	contract_points_test(0, Trump::NT, 2, 2, 1);
	contract_points_test(0, Trump::NT, 2, 4, 1);
}

TEST(ScorerTest, TestContractPointsMajorSuit)
{
	Trump trumps[] = {Trump::SPADES, Trump::HEARTS};
	for ( Trump trump : trumps) {
		contract_points_test(30, trump, 1, 1, 1);
		contract_points_test(60, trump, 1, 2, 1);
		contract_points_test(120, trump, 1, 4, 1);

		contract_points_test(60, trump, 2, 1, 2);
		contract_points_test(120, trump, 2, 2, 2);
		contract_points_test(240, trump, 2, 4, 2);

		contract_points_test(0, trump, 2, 1, 1);
		contract_points_test(0, trump, 2, 2, 1);
		contract_points_test(0, trump, 2, 4, 1);
	}
}

TEST(ScorerTest, TestContractPointsMinorSuit)
{
	Trump trumps[] = {Trump::CLUBS, Trump::DIAMONDS};
	for ( Trump trump : trumps) {
		contract_points_test(20, trump, 1, 1, 1);
		contract_points_test(40, trump, 1, 2, 1);
		contract_points_test(80, trump, 1, 4, 1);

		contract_points_test(40, trump, 2, 1, 2);
		contract_points_test(80, trump, 2, 2, 2);
		contract_points_test(160, trump, 2, 4, 2);

		contract_points_test(0, trump, 2, 1, 1);
		contract_points_test(0, trump, 2, 2, 1);
		contract_points_test(0, trump, 2, 4, 1);
	}
}