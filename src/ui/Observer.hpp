#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <memory>

namespace ui
{

template <class T>
class Observer
{
public:
    Observer(std::weak_ptr<T> target) : target(target){}
    virtual void notify() = 0;

protected:
    std::weak_ptr<T> target;
};

}

#endif // OBSERVER_HPP
