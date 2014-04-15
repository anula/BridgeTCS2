#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include <set>
#include <memory>

#include "Observer.hpp"

class Observable
{
public:
    void addObserver(std::weak_ptr<Observer> observer);
    bool delObserver(std::weak_ptr<Observer> observer);
    void update();
private:
    std::set<std::weak_ptr<Observer> > observers;
}

#endif // OBSERVABLE_HPP
