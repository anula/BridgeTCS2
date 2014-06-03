#include "ui/text/Application.hpp"


void ui::text::Application::notify(model::Application const & app) 
{
	if (app.state == model::Application::State::STARTED) {
		std::cout << indent << "Zapraszamy do gry!" << std::endl;
		app.getGame().sigModified.connect(
				[this] (model::IGame const & game) {
					gameView.notify(game);
				}
			);
	} else if (app.state == model::Application::State::FINISHED)
		std::cout << indent << "Dziękujemy za grę!" << std::endl;
}
