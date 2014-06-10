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
	} else if (app.state == model::Application::State::FINISHED) {
		std::cout << "Contract: " << std::endl;
		ui::text::Printer::print(app.getGame().result.contract);
		std::cout << std::endl;
		std::cout << "Tricks collected by declarer and his partner: " 
			<< app.getGame().result.tricksCollected << std::endl;
		std::cout << indent << "Dziękujemy za grę!" << std::endl;
	}
}
