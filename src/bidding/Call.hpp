#ifndef CALL_HPP
#define CALL_HPP

#include "Trump.hpp"

struct Call
{
  bool ifRedouble;
  bool ifDouble;
  bool ifPass;
  int value;
  Trump trump;
};

class CallFactory
{
public:
    static const Call createPass();
    static const Call createRedouble();
    static const Call createDouble();
    static const Call createStandard(int value, Trump trump);
};
#endif // CALL_HPP
