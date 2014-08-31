#include <gtest/gtest.h>

#include "model/Scorer.hpp"
#include "model/Score.hpp"
#include "model/Deal.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace model;

void contract_points_test(int expected, Trump trump, int value, int multiplier, int collected)
{
	Scorer scorer;
	DealResult result;
	Contract contract;

	contract.trump = trump;
	contract.value = value;
	contract.multiplier = multiplier;

	result.tricksCollected = collected + 6;
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

void ASSERT_SCORE(DealScore const & score, int contract, int overtrick, int slam, int insult, int penalty, int honor)
{
	ASSERT_EQ(contract, score.contractPoints);
	ASSERT_EQ(overtrick, score.overtrickPoints);
	ASSERT_EQ(slam, score.slamBonus);
	ASSERT_EQ(insult, score.insultBonus);
	ASSERT_EQ(penalty, score.penaltyPoints);
	ASSERT_EQ(honor, score.honorBonus);
}

void ASSERT_ABOVE_BELOW_LINE(Scorer const & scorer, int deal, int ns_below, int ns_above, int we_below, int we_above)
{
	ASSERT_EQ(deal, scorer.getPointsBelowLine(Scorer::SIDE_NS).size());	
	ASSERT_EQ(deal, scorer.getPointsBelowLine(Scorer::SIDE_WE).size());	
	ASSERT_EQ(deal, scorer.getPointsAboveLine(Scorer::SIDE_NS).size());	
	ASSERT_EQ(deal, scorer.getPointsAboveLine(Scorer::SIDE_WE).size());	

	ASSERT_EQ(ns_below, scorer.getPointsBelowLine(Scorer::SIDE_NS).back());
	ASSERT_EQ(ns_above, scorer.getPointsAboveLine(Scorer::SIDE_NS).back());
	ASSERT_EQ(we_below, scorer.getPointsBelowLine(Scorer::SIDE_WE).back());
	ASSERT_EQ(we_above, scorer.getPointsAboveLine(Scorer::SIDE_WE).back());
}

TEST(ScorerTest, TestSampleRubber)
{
	Scorer scorer;
	DealResult result;
	Contract contract;

	// First Deal -  South bids 2NT making 3.
	// Only the contract points (70) are scored below the line;
	// the overtrick points (30) are scored above the line.
	contract.trump = Trump::NT;
	contract.value = 2;
	contract.multiplier = 1;
	// We assume that players are numbered starting at 0-NE clockwise
	contract.declarer = 2;

	result.tricksCollected = 6 + 3;
	result.contract = contract;

	ASSERT_EQ(0, scorer.getDealScores().size());	
	scorer.update(result);
	ASSERT_EQ(1, scorer.getDealScores().size());	


	ASSERT_SCORE(scorer.getDealScores().back(), 70, 30, 0, 0, 0, 0);
	ASSERT_FALSE(scorer.isGameOver());
	ASSERT_ABOVE_BELOW_LINE(scorer, 1, 70, 30, 0, 0);

	
	// Second deal - West bids and makes 4♥. This scores 120 contract points below the line;
	// since there are no overtricks, no points are scored above the line.
	// The accumulation of 100 or more points below the line constitutes the end of the first game
	contract.trump = Trump::HEARTS;
	contract.value = 4;
	contract.multiplier = 1;
	contract.declarer = 3;

	result.tricksCollected = 6 + 4;
	result.contract = contract;

	ASSERT_EQ(1, scorer.getDealScores().size());	
	scorer.update(result);
	ASSERT_EQ(2, scorer.getDealScores().size());	


	ASSERT_SCORE(scorer.getDealScores().back(), 120, 0, 0, 0, 0, 0);
	ASSERT_FALSE(scorer.isGameOver());
	ASSERT_ABOVE_BELOW_LINE(scorer, 2, 0, 0, 120, 0);

	// Third deal - West bids 5♣ and goes down 2, vulnerable, undoubled.
	// This scores 200 penalty points for North-South above the line.
	contract.trump = Trump::CLUBS;
	contract.value = 5;
	contract.multiplier = 1;
	contract.declarer = 3;

	result.tricksCollected = 6 + 3;
	result.contract = contract;

	ASSERT_EQ(2, scorer.getDealScores().size());	
	scorer.update(result);
	ASSERT_EQ(3, scorer.getDealScores().size());	


	ASSERT_SCORE(scorer.getDealScores().back(), 0, 0, 0, 0, 200, 0);
	ASSERT_FALSE(scorer.isGameOver());
	ASSERT_ABOVE_BELOW_LINE(scorer, 3, 0, 200, 0, 0);

	// Fourth deal - South bids 4♠ doubled, not vulnerable and makes 5.
	// North-South score 240 contract tricks below the line,
	// 100 overtrick points above the line and 50 points for 'insult' above the line.
	contract.trump = Trump::SPADES;
	contract.value = 4;
	contract.multiplier = 2;
	contract.declarer = 2;

	result.tricksCollected = 6 + 5;
	result.contract = contract;

	ASSERT_EQ(3, scorer.getDealScores().size());	
	scorer.update(result);
	ASSERT_EQ(4, scorer.getDealScores().size());	


	ASSERT_SCORE(scorer.getDealScores().back(), 240, 100, 0, 50, 0, 0);
	ASSERT_FALSE(scorer.isGameOver());
	ASSERT_ABOVE_BELOW_LINE(scorer, 4, 240, 150, 0, 0);

	// Fifth deal - North bids 3♣ and makes 4 scoring 60 contract points below the line
	// and 20 overtrick points above the line.
	contract.trump = Trump::CLUBS;
	contract.value = 3;
	contract.multiplier = 1;
	contract.declarer = 0;

	result.tricksCollected = 6 + 4;
	result.contract = contract;

	ASSERT_EQ(4, scorer.getDealScores().size());	
	scorer.update(result);
	ASSERT_EQ(5, scorer.getDealScores().size());	


	ASSERT_SCORE(scorer.getDealScores().back(), 60, 20, 0, 0, 0, 0);
	ASSERT_FALSE(scorer.isGameOver());
	ASSERT_ABOVE_BELOW_LINE(scorer, 5, 60, 20, 0, 0);

	// Sixth deal - East bids and makes 6♦ - a small slam holding all five top honors.
	// This scores a game of 120 contract points and earns a slam bonus of 750 points above the line
	// (East-West being vulnerable).
	// Having again accumulated 100 or more points below the line, East-West win a second game;
	// a horizontal line is drawn to end the rubber.
	contract.trump = Trump::DIAMONDS;
	contract.value = 6;
	contract.multiplier = 1;
	contract.declarer = 1;

	result.tricksCollected = 6 + 6;
	result.contract = contract;

	ASSERT_EQ(5, scorer.getDealScores().size());	
	scorer.update(result);
	ASSERT_EQ(6, scorer.getDealScores().size());	

	ASSERT_SCORE(scorer.getDealScores().back(), 120, 0, 750, 0, 0, 0);
	ASSERT_TRUE(scorer.isGameOver());
	//  East-West have won a slow rubber and receive a 500 point rubber bonus above the line.
	ASSERT_ABOVE_BELOW_LINE(scorer, 6, 0, 0, 120, 750 + 500);

	// NS should have 770 in total
	std::vector<int> const & ns_below = scorer.getPointsBelowLine(Scorer::SIDE_NS);
	std::vector<int> const & ns_above = scorer.getPointsAboveLine(Scorer::SIDE_NS);
	ASSERT_EQ(770, std::accumulate(ns_below.begin(), ns_below.end(), 0) + std::accumulate(ns_above.begin(), ns_above.end(), 0));
	// WE should have 1490
	std::vector<int> const & we_below = scorer.getPointsBelowLine(Scorer::SIDE_WE);
	std::vector<int> const & we_above = scorer.getPointsAboveLine(Scorer::SIDE_WE);
	ASSERT_EQ(1490, std::accumulate(we_below.begin(), we_below.end(), 0) + std::accumulate(we_above.begin(), we_above.end(), 0));

	// After game is over, next update should thrown an exception
	ASSERT_THROW(scorer.update(result), std::logic_error);
}
