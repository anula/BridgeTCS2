#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "ui/Observable.hpp"

namespace model
{

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

} // namespace model

#endif // APPLICATION_HPP
