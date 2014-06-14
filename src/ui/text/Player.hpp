#ifndef UI_TEXT_PLAYER_HPP
#define UI_TEXT_PLAYER_HPP

#include "model/IPlayer.hpp"


namespace ui 
{

namespace text
{

class Player : public model::IPlayer
{
	static const char ranks[];
	static const char suits[];
public: 
    model::Card getCard(model::Hand const & hand, model::Bidding const & bidding, model::Play const & play);
    model::Card getDummyCard(model::Hand const & hand, model::Bidding const & bidding, model::Play const & play);
    model::Call getCall(model::Hand const & hand, model::Bidding const & bidding);
private:
    model::Card strategy(bool fromDummy, model::Hand const & playerHand, model::Bidding const & bidding, model::Play const & play);
    model::Hand myHand;
};

} // namespace text

} // namespace ui

#endif // UI_TEXT_PLAYER_HPP

