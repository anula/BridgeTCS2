#ifndef UI_TEXT_PLAYER_HPP
#define UI_TEXT_PLAYER_HPP

#include "model/IPlayer.hpp"


namespace ui 
{

namespace text
{

class Player : public model::IPlayer
{
public: 
    model::Card getCard(model::Hand const & hand, model::Bidding const & bidding, model::Play const & play) const;
    model::Call getCall(model::Hand const & hand, model::Bidding const & bidding) const;
};

} // namespace text

} // namespace ui

#endif // UI_TEXT_PLAYER_HPP

