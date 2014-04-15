void Observable::addObserver(std::weak_ptr<Observer> observer)
{
    observers.insert(observer);
}

bool Observable::delObserver(std::weak_ptr<Observer> observer)
{
    return observers.erase(observer);
}

void Observable::update()
{
    for(auto it : observers) {
        auto ptr = it.lock();
        if(!ptr)
            delObserver(it);
        else
            ptr->notify();
    }
}
