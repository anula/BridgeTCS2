#ifndef DEAL_HPP
#define DEAL_HPP

#include <array>
#include <utility>

#include "Arbiter.hpp"
#include "Bidding.hpp"
#include "Contract.hpp"
#include "Deck.hpp"
#include "../ui/Observable.hpp"

namespace model
{

struct DealResult
{
  static const int BOOK = 6;
  /* Tricks collected by pair who begins.
   * If during bidding everyone bid PASS 
   * it is equal zero.
   */
  int tricksCollected;

  /* Contract bidded by pair who begins.
   */
  Contract contract;

  int getOvertricks() const
  {
      return tricksCollected - BOOK;
  }

  bool isSmallSlam() const
  {
      return tricksCollected == 6;
  }

  bool isGrandSlam() const
  {
      return tricksCollected == 7;
  }

  bool wasMade() const
  {
      return contract.value <= tricksCollected;
  }

  bool isDown() const
  {
      return !wasMade();
  }

};

class Deal : public ui::Observable<Deal>
{
  public: 
    Deal(std::array<Arbiter, 4> & arbiters, int firstPlayer) : firstPlayer(firstPlayer), arbiters(arbiters),
           biddingFinished(false), playFinished(false), play(nullptr)
    {
    }
    
    bool biddingFinished;
    bool playFinished;

    /*
     * Main method of class Deal.
     * It causes to perform whole one deal.
     */
    void perform();

    /*
     * To call after perform returns.
     * Returns result of deal.
     */
    DealResult getDealResult() const {
      return dealResult;
    }
    
    Contract getContract() const {
        if (bidding.stillGoing())
            throw 666;
        return contract;
    }
    
    const Bidding & getBidding() const {
    	return bidding;
    }
    
    Play* getPlay() const {
    	return play;
    }

private:
    std::array<Arbiter, 4> & arbiters;
    int firstPlayer;
    Contract contract;
    DealResult dealResult;
    Bidding bidding;
    Play* play;

    int performBidding();
    int performPlay(int declarer);
};

} // namespace model

#endif // DEAL_HPP
