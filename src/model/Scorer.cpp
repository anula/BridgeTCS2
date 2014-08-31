#include "Scorer.hpp"
#include "Card.hpp"
#include "Score.hpp"

namespace model
{

	bool isMinor(Trump const & trump) {
		return trump == model::Trump::DIAMONDS || trump == model::Trump::CLUBS;
	}

	bool Scorer::isGameOver() const
	{
		return wins[Scorer::SIDE_NS] >= Scorer::GAMES_TO_WIN || wins[Scorer::SIDE_WE] >= Scorer::GAMES_TO_WIN;
	}

	void Scorer::update(DealResult const & dealResult) 
	{
		if ( isGameOver() )
			throw std::logic_error("Rubber is already finished");
		
		DealScore score;
		int multiplier = dealResult.contract.multiplier;
		int value = dealResult.contract.value;
		int declarer = dealResult.contract.declarer;
		Trump trump = dealResult.contract.trump;
		// Set declaring side based on the declarer from contract
		int side = 0;
		if ( declarer == 0 || declarer == 2 )
		{
			side = Scorer::SIDE_NS;
		}
		else
		{
			side = Scorer::SIDE_WE;
		}

		/* Count contract points */
		if ( dealResult.wasMade() && value > 0 )
		{
			/* For notrump, there is distinction between 1st and subsequent tricks */
			if ( trump == model::Trump::NT )
			{
				/* Calculate points for the first trick */
				score.contractPoints += multiplier * FIRST_NT_CONTRACT_POINTS;

				/* Calculate points for the subsequent tricks */
				if ( value > 1 )
				{
					score.contractPoints += multiplier * SUBSEQUENT_NT_CONTRACT_POINTS * (value - 1);
				}
			}
			else if ( isMinor(trump) )
			{
				score.contractPoints += multiplier * value * MINOR_CONTRACT_POINTS;
			}
			else
			{
				score.contractPoints += multiplier * value * MAJOR_CONTRACT_POINTS;
			}
		}

		/* Count overtrick points */
		int overtricks = dealResult.getOvertricks();
		if ( overtricks > 0 )
		{
			/* Reouble */
			if ( multiplier == 4 )
			{
				if ( isVulnerable[side] ) score.overtrickPoints += overtricks * VULNERABLE_REDOUBLED_OVERTRICK_POINTS;
				else score.overtrickPoints += overtricks * NOT_VULNERABLE_REDOUBLED_OVERTRICK_POINTS;
			}
			/* Double */
			else if ( multiplier == 2 )
			{
				if ( isVulnerable[side] ) score.overtrickPoints += overtricks * VULNERABLE_DOUBLED_OVERTRICK_POINTS;
				else score.overtrickPoints += overtricks * NOT_VULNERABLE_DOUBLED_OVERTRICK_POINTS;

			}
			/* No multiplication */
			else if ( multiplier == 1 )
			{
				if ( trump == model::Trump::NT ) score.overtrickPoints += multiplier * NT_OVERTRICK_POINTS;
				else if ( isMinor(trump) ) score.overtrickPoints += overtricks * MINOR_OVERTRICK_POINTS;
				else score.overtrickPoints += overtricks * MAJOR_OVERTRICK_POINTS;
			}
		}

		/* Slam bonus */
		if ( dealResult.isGrandSlam() )
		{
			if ( isVulnerable[side] ) score.slamBonus += VULNERABLE_GRAND_SLAM_POINTS;
			else score.slamBonus += NOT_VULNERABLE_GRAND_SLAM_POINTS;
		}
		else if ( dealResult.isSmallSlam() )
		{
			if ( isVulnerable[side] ) score.slamBonus += VULNERABLE_SMALL_SLAM_POINTS;
			else score.slamBonus += NOT_VULNERABLE_SMALL_SLAM_POINTS;
		}

		/* Doubled or redoubled bonus */
		if ( dealResult.wasMade() )
		{
			if ( multiplier == 4 ) score.insultBonus += REDOUBLED_INSULT_POINTS;
			if ( multiplier == 2 ) score.insultBonus += DOUBLED_INSULT_POINTS;
		}

		/* Penalty points */
		if ( dealResult.isDown() )
		{
			int undertricks = -dealResult.getOvertricks();
			if ( multiplier == 1 )
			{
				if ( isVulnerable[side] ) score.penaltyPoints += undertricks * VULNERABLE_UNDOUBLED_PENALTY_POINTS;
				else score.penaltyPoints += undertricks * NOT_VULNERABLE_UNDOUBLED_PENALTY_POINTS;	
			} else {
				ScoringScheme::iterator scoringScheme;
				if ( multiplier == 4 )
				{
					if ( isVulnerable[side] ) scoringScheme = VULNERABLE_REDOUBLED_PENALTY_POINTS.begin();
					else scoringScheme = NOT_VULNERABLE_REDOUBLED_PENALTY_POINTS.begin();	
				}
				else if ( multiplier == 2 )
				{
					if ( isVulnerable[side] ) scoringScheme = VULNERABLE_DOUBLED_PENALTY_POINTS.begin();
					else scoringScheme = NOT_VULNERABLE_DOUBLED_PENALTY_POINTS.begin();	
				}

				/* As long as there are undertricks for which penalty points were not yet assigned */
				while ( undertricks > 0 )
				{
					/* Check how many undertricks follow the same scheme */
					int toCount = std::min(undertricks, scoringScheme->first);
					/* Update points acordingly */
					score.penaltyPoints += toCount * scoringScheme->second;
					/* Set remaining undertricks and interate to the next scheme */
					undertricks -= toCount;
					std::advance(scoringScheme, 1);
				}

			}
		}

		// Save detailed score for the deal
		deals.push_back(score);

		// Count points above and below the line
		int opposingSide = Scorer::getOpposingSide(side);

		// Only contract points are scored over the line
		int belowDeclarerSide = score.contractPoints;
		belowTheLine[side].push_back(belowDeclarerSide);
		// Remaining points with the exception of pentaly points are written above the line
		aboveTheLine[side].push_back(score.slamBonus + score.overtrickPoints + score.honorBonus + score.insultBonus);
		// Opposing team cannot score below the line in this deal
		belowTheLine[opposingSide].push_back(0);
		// Penalty points are added above their line
		aboveTheLine[opposingSide].push_back(score.penaltyPoints);

		// If declaring team has scored more than the game limit,
		// increase game counter and reinitialize game related variables
		scoredThisGame[side] += belowDeclarerSide;
		if ( scoredThisGame[side] > Scorer::POINTS_PER_GAME ) {
			scoredThisGame[Scorer::SIDE_WE] = 0;
			scoredThisGame[Scorer::SIDE_NS] = 0;
			wins[side] += 1;
			isVulnerable[side] = true;
		}

		// if rubber has ended, add bonus points to winning team
		if ( isGameOver() ) {
			if ( isVulnerable[opposingSide] ){
				aboveTheLine[side].back() += Scorer::SLOW_RUBBER_BONUS;
			} else {
				aboveTheLine[side].back() += Scorer::FAST_RUBBER_BONUS;
			}
		}
	}

	std::vector<DealScore> const & Scorer::getDealScores() const
	{
		return deals;
	}

	std::vector<int> const & Scorer::getPointsBelowLine(int side) const
	{
		return belowTheLine[side];
	}

	std::vector<int> const & Scorer::getPointsAboveLine(int side) const
	{
		return aboveTheLine[side];
	}

	int Scorer::getOpposingSide(int side) 
	{
		return 1 - side;
	}

}
