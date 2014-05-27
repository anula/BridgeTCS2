#include <functional>

#include "model/Application.hpp"
#include "ui/text/Application.hpp"


int main(int argc, char** argv) 
{
    model::Application application; // dziedziczy po Observable
    ui::text::Application appView(1);
    application.sigModified.connect(
        [&appView] (model::Application const & app) {
            appView.notify(app);
        }
    );
    application.run();
    return 0;
}
