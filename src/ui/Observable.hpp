#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include <set>
#include <memory>
#include <functional>

#include "Observer.hpp"

namespace ui
{

template <class T>
class Observable : public std::enable_shared_from_this<Observable<T>>
{
public:
    using ObserverPtr = std::weak_ptr<Observer<T>>;
    Observable() : observers([](ObserverPtr const & lhs, ObserverPtr const & rhs){return lhs.lock() < rhs.lock();}) {}
    void addObserver(ObserverPtr observer)
    {
        observers.insert(observer);
    }

    bool delObserver(ObserverPtr observer)
    {
        return observers.erase(observer);
    }

    void update()
    {
        for(auto it : observers) 
        {
            auto ptr = it.lock();
            if(!ptr)
                delObserver(it);
            else
                ptr->notify();
        }
    }

private:
    std::set<ObserverPtr, std::function<bool (ObserverPtr const &, ObserverPtr const &)>> observers;
};

}

#endif // OBSERVABLE_HPP
