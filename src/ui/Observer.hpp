#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <memory>

namespace ui
{

template <class T>
class Observer
{
public:
    virtual void notify() = 0;
};

}

#endif // OBSERVER_HPP
