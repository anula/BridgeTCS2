#ifndef SCORE_HPP
#define SCORE_HPP

/* Summarizes score within a single deal */
struct DealScore
{
	DealScore() : contractPoints(0), overtrickPoints(0), slamBonus(0), insultBonus(0), penaltyPoints(0), honorBonus(0) {}

	int contractPoints;
	int overtrickPoints;
	int slamBonus;
	int insultBonus;
	int penaltyPoints;
	int honorBonus;

};

#endif