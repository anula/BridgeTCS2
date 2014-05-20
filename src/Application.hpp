#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "ui/Observable.hpp"
#include "model/DummyComputerPlayer.hpp"

namespace model
{

class Application : public ui::Observable<Application>
{
    
public:

    Application() {}

    void run();

};

} // namespace model

#endif // APPLICATION_HPP
