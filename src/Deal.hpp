#ifndef DEAL_HPP
#define DEAL_HPP

#include "Arbiter.hpp"
#include "Deck.hpp"

struct DealResult
{
  /* Tricks collected by pair who begins.
   * If during bidding everyone bid PASS 
   * it is equal zero.
   */
  int tricksCollected;

  /* Contract bidded by pair who begins.
   */
  Contract contract;
};

class Deal
{
  public: 
    Deal(std::array<Arbiter, 4> ref arbiters, int firstPlayer) : firstPlayer(firstPlayer), arbiters(arbiters)
    {
    }

    /*
     * Main method of class Deal.
     * It causes to perform whole one deal.
     */
    void perform();

    /*
     * To call after perform returns.
     * Returns result of deal.
     */
    DealResult getDealResult() {
      return dealResult;
    }

  private:
    std::array<Arbiter, 4> arbiters;
    int firstPlayer;
    Contract contract;
    DealResult dealResult;
    
    int performBidding();
    void performPlay();
};

#endif // DEAL_HPP
