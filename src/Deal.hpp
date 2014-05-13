#ifndef DEAL_HPP
#define DEAL_HPP

#include <array>
#include <utility>

#include "Arbiter.hpp"
#include "Bidding.hpp"
#include "Contract.hpp"
#include "Deck.hpp"

namespace model
{

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
    Deal(std::array<Arbiter, 4> & arbiters, int firstPlayer) : firstPlayer(firstPlayer), arbiters(arbiters)
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
    DealResult getDealResult() const {
      return dealResult;
    }

  private:
    std::array<Arbiter, 4> & arbiters;
    int firstPlayer;
    Contract contract;
    DealResult dealResult;
    
    int performBidding();
    int performPlay(int declarer);
};

} // namespace model

#endif // DEAL_HPP
