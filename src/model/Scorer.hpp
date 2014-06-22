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
	/* usage: isVunerable[Scorer::SIDE_XX] */
	bool isVunerable[2];
	std::vector<DealScore> deals;

	void saveScore(DealScore const & dealScore);

public:
	/* Counts score based on result of the deal */
	void update(DealResult const &);

	/* Getter for "deals" field */
	std::vector<DealScore> const & getDealScores();

	/* Side constants */
	static const int SIDE_NS = 0;
	static const int SIDE_WE = 1;

	/* Contract scores */
	static const int FIRST_NT_CONTRACT_POINTS= 40;
	static const int SUBSEQUENT_NT_CONTRACT_POINTS = 30;
	static const int MAJOR_CONTRACT_POINTS = 30;
	static const int MINOR_CONTRACT_POINTS = 20;

	/* Overtricks scores */
	static const int VUNERABLE_REDOUBLED_OVERTRICK_POINTS = 400;
	static const int NOT_VUNERABLE_REDOUBLED_OVERTRICK_POINTS = 200;
	static const int VUNERABLE_DOUBLED_OVERTRICK_POINTS = 200;
	static const int NOT_VUNERABLE_DOUBLED_OVERTRICK_POINTS = 100;

	static const int NT_OVERTRICK_POINTS = 30;
	static const int MAJOR_OVERTRICK_POINTS = 30;
	static const int MINOR_OVERTRICK_POINTS = 20;

	/* Slam scoring */
	static const int VUNERABLE_GRAND_SLAM_POINTS = 1500;
	static const int NOT_VUNERABLE_GRAND_SLAM_POINTS = 1000;
	static const int VUNERABLE_SMALL_SLAM_POINTS = 750;
	static const int NOT_VUNERABLE_SMALL_SLAM_POINTS = 500;

	/* Insult bonuses */
	static const int REDOUBLED_INSULT_POINTS = 100;
	static const int DOUBLED_INSULT_POINTS = 50;

	/* Penalty points */
	static const int VUNERABLE_UNDOUBLED_PENALTY_POINTS = 100;
	static const int NOT_VUNERABLE_UNDOUBLED_PENALTY_POINTS = 50;

	ScoringScheme VUNERABLE_DOUBLED_PENALTY_POINTS = {{
		{1, 200},
		{2, 300},
		{10, 300},
	}};

	ScoringScheme NOT_VUNERABLE_DOUBLED_PENALTY_POINTS = {{
		{1, 200},
		{2, 300},
		{10, 300},
	}};

	ScoringScheme VUNERABLE_REDOUBLED_PENALTY_POINTS = {{
		{1, 400},
		{2, 600},
		{10, 600},
	}};

	ScoringScheme NOT_VUNERABLE_REDOUBLED_PENALTY_POINTS = {{
		{1, 200},
		{2, 400},
		{10, 600},
	}};

};

}
#endif // SCORER_H
