#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "ui/Observable.hpp"

class Application : public ui::Observable<Application>
{
    
public:
    void run()
    {
        update();
    }
};

#endif // APPLICATION_HPP
