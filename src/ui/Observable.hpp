#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include <set>
#include <memory>

#include "Observer.hpp"

namespace ui
{

template <class T>
class Observable
{
public:
    void addObserver(std::weak_ptr<Observer<T>> observer)
    {
        observers.insert(observer);
    }
    bool delObserver(std::weak_ptr<Observer<T>> observer)
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
    std::set<std::weak_ptr<Observer<T>>> observers;
};

}

#endif // OBSERVABLE_HPP
