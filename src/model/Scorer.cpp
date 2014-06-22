#include "Scorer.hpp"
#include "Card.hpp"
#include "Score.hpp"

namespace model
{

	bool isMinor(Trump const & trump) {
		return trump == model::Trump::DIAMONDS || trump == model::Trump::CLUBS;
	}

	void Scorer::update(DealResult const & dealResult) 
	{
		DealScore score;
		int multiplier = dealResult.contract.multiplier;
		Trump trump = dealResult.contract.trump;
		// TODO - set declaring side
		int side = 0;

		/* Count contract points */
		if ( dealResult.wasMade() and dealResult.tricksCollected > 0 )
		{
			/* For notrump, there is distinction between 1st and subsequent tricks */
			if ( trump == model::Trump::NT )
			{
				/* Calculate points for the first trick */
				score.contractPoints += multiplier * FIRST_NT_CONTRACT_POINTS;

				/* Calculate points for the subsequent tricks */
				if ( dealResult.tricksCollected > 1 )
				{
					score.contractPoints += multiplier * SUBSEQUENT_NT_CONTRACT_POINTS * (dealResult.tricksCollected - 1);
				}
			}
			else if ( isMinor(trump) )
			{
				score.contractPoints += multiplier * dealResult.tricksCollected * MINOR_CONTRACT_POINTS;
			}
			else
			{
				score.contractPoints += multiplier * dealResult.tricksCollected * MAJOR_CONTRACT_POINTS;
			}
		}

		/* Count overtrick points */
		int overtricks = dealResult.getOvertricks();
		if ( overtricks > 0 )
		{
			/* Reouble */
			if ( multiplier == 4 )
			{
				if ( isVunerable[side] ) score.overtrickPoints += overtricks * VUNERABLE_REDOUBLED_OVERTRICK_POINTS;
				else score.overtrickPoints += overtricks * NOT_VUNERABLE_REDOUBLED_OVERTRICK_POINTS;
			}
			/* Double */
			else if ( multiplier == 2 )
			{
				if ( isVunerable[side] ) score.overtrickPoints += overtricks * VUNERABLE_DOUBLED_OVERTRICK_POINTS;
				else score.overtrickPoints += overtricks * NOT_VUNERABLE_DOUBLED_OVERTRICK_POINTS;

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
			if ( isVunerable[side] ) score.slamBonus += VUNERABLE_GRAND_SLAM_POINTS;
			else score.slamBonus += NOT_VUNERABLE_GRAND_SLAM_POINTS;
		}
		else if ( dealResult.isSmallSlam() )
		{
			if ( isVunerable[side] ) score.slamBonus += VUNERABLE_SMALL_SLAM_POINTS;
			else score.slamBonus += NOT_VUNERABLE_SMALL_SLAM_POINTS;
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
				if ( isVunerable[side] ) score.penaltyPoints += undertricks * VUNERABLE_UNDOUBLED_PENALTY_POINTS;
				else score.penaltyPoints += undertricks * NOT_VUNERABLE_UNDOUBLED_PENALTY_POINTS;	
			} else {
				ScoringScheme::iterator scoringScheme;
				if ( multiplier == 4 )
				{
					if ( isVunerable[side] ) scoringScheme = VUNERABLE_REDOUBLED_PENALTY_POINTS.begin();
					else scoringScheme = NOT_VUNERABLE_REDOUBLED_PENALTY_POINTS.begin();	
				}
				else if ( multiplier == 2 )
				{
					if ( isVunerable[side] ) scoringScheme = VUNERABLE_DOUBLED_PENALTY_POINTS.begin();
					else scoringScheme = NOT_VUNERABLE_DOUBLED_PENALTY_POINTS.begin();	
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

		saveScore(score);
	}

	void Scorer::saveScore(DealScore const & dealScore)
	{
		// TODO Update summarized team scores
		deals.push_back(dealScore);
	}

	std::vector<DealScore> const & Scorer::getDealScores()
	{
		return deals;
	}

}
