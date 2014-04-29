#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include <set>
#include <memory>

#include "Observer.hpp"

namespace ui
{

template <class T>
class Observable : public std::enable_shared_from_this<Observable<T>>
{
public:
    using ObserverPtr = std::weak_ptr<Observer<T>>;
    void addObserver(ObserverPtr observer)
    {
        observers.insert(observer);
        observer.lock()->setTarget(this->shared_from_this());
    }

    bool delObserver(ObserverPtr observer)
    {
        observer.lock()->setTarget(nullptr);
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
    std::set<ObserverPtr> observers;
};

}

#endif // OBSERVABLE_HPP
