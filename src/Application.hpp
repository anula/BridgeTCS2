#include "ui/Observable.hpp"

class Application : public ui::Observable<Application>
{
    
public:
    void run()
    {
        update();
    }
};

