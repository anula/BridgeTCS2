#ifndef SCORER_H
#define SCORER_H

#include <vector>
#include "Deal.hpp"
#include "Score.hpp"

namespace model
{

typedef std::array<std::pair<int, int>, 3> ScoringScheme;

class Scorer 
{
	/* usage: isVulnerable[Scorer::SIDE_XX] */
	bool isVulnerable[2];
	std::vector<DealScore> deals;

	/* Vector of points scored above / below line in consecutive deals */
	std::vector<int> belowTheLine[2];
	std::vector<int> aboveTheLine[2];

	/* Number of points scored this game by the teams */
	int scoredThisGame[2];

	int wins[2];

	void saveScore(DealScore const & dealScore);

	static int getOpposingSide(int side);

public:
	Scorer()
	{
		scoredThisGame[0] = scoredThisGame[1] = 0;
		isVulnerable[0] = isVulnerable[1] = false;
		wins[0] = wins[1] = 0;
	}

	/* Counts score based on result of the deal */
	void update(DealResult const &);
	bool isGameOver() const;

	/* Getter for "deals" field */
	std::vector<DealScore> const & getDealScores() const;

	/* Getters for points below/above the line */
	std::vector<int> const & getPointsBelowLine(int side) const;
	std::vector<int> const & getPointsAboveLine(int side) const;

	/* Side constants */
	static const int SIDE_NS = 0;
	static const int SIDE_WE = 1;

	/* Limits */
	static const int POINTS_PER_GAME = 100;
	static const int GAMES_TO_WIN = 2;

	/* Contract scores */
	static const int FIRST_NT_CONTRACT_POINTS= 40;
	static const int SUBSEQUENT_NT_CONTRACT_POINTS = 30;
	static const int MAJOR_CONTRACT_POINTS = 30;
	static const int MINOR_CONTRACT_POINTS = 20;

	/* Overtricks scores */
	static const int VULNERABLE_REDOUBLED_OVERTRICK_POINTS = 400;
	static const int NOT_VULNERABLE_REDOUBLED_OVERTRICK_POINTS = 200;
	static const int VULNERABLE_DOUBLED_OVERTRICK_POINTS = 200;
	static const int NOT_VULNERABLE_DOUBLED_OVERTRICK_POINTS = 100;

	static const int NT_OVERTRICK_POINTS = 30;
	static const int MAJOR_OVERTRICK_POINTS = 30;
	static const int MINOR_OVERTRICK_POINTS = 20;

	/* Slam scoring */
	static const int VULNERABLE_GRAND_SLAM_POINTS = 1500;
	static const int NOT_VULNERABLE_GRAND_SLAM_POINTS = 1000;
	static const int VULNERABLE_SMALL_SLAM_POINTS = 750;
	static const int NOT_VULNERABLE_SMALL_SLAM_POINTS = 500;

	/* Insult bonuses */
	static const int REDOUBLED_INSULT_POINTS = 100;
	static const int DOUBLED_INSULT_POINTS = 50;

	/* Penalty points */
	static const int VULNERABLE_UNDOUBLED_PENALTY_POINTS = 100;
	static const int NOT_VULNERABLE_UNDOUBLED_PENALTY_POINTS = 50;

	ScoringScheme VULNERABLE_DOUBLED_PENALTY_POINTS = {{
		{1, 200},
		{2, 300},
		{10, 300},
	}};

	ScoringScheme NOT_VULNERABLE_DOUBLED_PENALTY_POINTS = {{
		{1, 200},
		{2, 300},
		{10, 300},
	}};

	ScoringScheme VULNERABLE_REDOUBLED_PENALTY_POINTS = {{
		{1, 400},
		{2, 600},
		{10, 600},
	}};

	ScoringScheme NOT_VULNERABLE_REDOUBLED_PENALTY_POINTS = {{
		{1, 200},
		{2, 400},
		{10, 600},
	}};

	/* Rubber bonuses */
	static const int FAST_RUBBER_BONUS = 700;
	static const int SLOW_RUBBER_BONUS = 500;

};

}
#endif // SCORER_H
