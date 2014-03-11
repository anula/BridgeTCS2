#ifndef BIDDINGCONSTRAINT_HPP
#define BIDDINGCONSTRAINT_HPP

struct BiddingConstraint
{
  int value;
  Trump trump;
  bool ifDouble;
  bool ifRedouble;

  bool satisfies(Call const& call) const;
};
#endif // BIDDINGCONSTRAINT_HPP 
