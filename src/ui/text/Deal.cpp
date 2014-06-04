#include "ui/text/Deal.hpp"

void ui::text::Deal::notify(model::Deal const & deal)
{
	if(!deal.biddingFinished)
		deal.getBidding().sigModified.connect(
    		[this] (model::Bidding const & bidding) {
        		biddingView.notify(bidding);
    		}
		);
	else
		deal.getPlay().sigModified.connect(
    		[this] (model::Play const & play) {
        		playView.notify(play);
    		}
		);
}
