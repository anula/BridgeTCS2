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
    void setTarget(std::weak_ptr<T> t) {
        target = t;
    }
protected:
    std::weak_ptr<T> target;
};

}

#endif // OBSERVER_HPP
