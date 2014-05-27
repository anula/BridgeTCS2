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
  /* Tricks collected by pair who begins.
   * If during bidding everyone bid PASS 
   * it is equal zero.
   */
  int tricksCollected;

  /* Contract bidded by pair who begins.
   */
  Contract contract;
};

class Deal : public ui::Observable<Deal>
{
  public: 
    Deal(std::array<Arbiter, 4> & arbiters, int firstPlayer) : firstPlayer(firstPlayer), arbiters(arbiters),
           biddingFinished(false), playFinished(false)
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

  private:
    std::array<Arbiter, 4> & arbiters;
    int firstPlayer;
    Contract contract;
    DealResult dealResult;
    Bidding bidding;

    int performBidding();
    int performPlay(int declarer);
};

} // namespace model

#endif // DEAL_HPP
