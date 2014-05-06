#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "ui/Observable.hpp"

class Application : public ui::Observable<Application>
{
    
public:

    Application() : name("IHaveNoIdeaWhatImDoing") {}

    void run()
    {
        sigModified(*this);
    }
    std::string name;

};

#endif // APPLICATION_HPP
