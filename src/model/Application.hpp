#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "ui/Observable.hpp"
#include "model/DummyComputerPlayer.hpp"

namespace model
{

class Application : public ui::Observable<Application>
{
    
public:
    bool started;
    bool finished;

    Application() : started(false), finished(false) {}
    void run();
};

} // namespace model

#endif // APPLICATION_HPP
