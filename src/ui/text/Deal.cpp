#include "ui/text/Deal.hpp"

void ui::text::Deal::notify(model::Deal const & deal)
{
	deal.getBidding().sigModified.connect(
		[this] (model::Bidding const & bidding) {
    		biddingView.notify(bidding);
		}
	);
	if(deal.getPlay() != nullptr)
		deal.getPlay()->sigModified.connect(
    		[this] (model::Play const & play) {
        		playView.notify(play);
    		}
		);
}
