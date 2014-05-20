#ifndef UI_TEXT_PLAYER_HPP
#define UI_TEXT_PLAYER_HPP

#include "model/IPlayer.hpp"


namespace ui 
{

namespace text
{

class Player : public IPlayer
{
public: 
    model::Card getCard(model::Hand const & hand, model::Bidding const & bidding, model::Play const & play);
    model::Call getCall(model::Hand const & hand, model::Bidding const & bidding);
};

} // namespace text

} // namespace ui

#endif // UI_TEXT_PLAYER_HPP

