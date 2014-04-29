#ifndef OBSERVER_HPP
#define OBSERVER_HPP

namespace ui
{

    class Observer
    {
    public:
        virtual void notify() = 0;
    };

}

#endif // OBSERVER_HPP
