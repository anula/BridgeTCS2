#include <functional>

#include "Application.hpp"
#include "ui/text/Application.hpp"


int main(int argc, char** argv) 
{
    Application application;
    ui::text::Application appView;
    application.sigModified.connect(
        [&appView] (Application const & app) {
            appView.notify(app);
        }
    );
    application.run();
    return 0;
}
