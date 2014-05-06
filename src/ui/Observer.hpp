#ifndef UI_OBSERVER_HPP
#define UI_OBSERVER_HPP

#include <memory>

namespace ui
{

template <class T>
class Observer
{
public:
    virtual void notify(T const &) = 0;
};

}

#endif // UI_OBSERVER_HPP
