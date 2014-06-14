#include "ui/text/Application.hpp"
#include <boost/algorithm/string/erase.hpp>
#include <boost/algorithm/string.hpp>

void ui::text::Application::notify(model::Application const & app) 
{
	if (app.state == model::Application::State::STARTED) {
		std::cout << indent << "Welcome!" << std::endl;
        std::cout << indent << "Type :quit to exit BridgeTCS. Enter anything else to start the game!" << std::endl;
        std::string tmp;
        if (!getline(std::cin, tmp)) {
            throw new std::runtime_error("Game interrupted");
        }
        boost::erase_all(tmp, " ");
        boost::to_lower(tmp);
        if(tmp != ":quit") {
            app.getGame().sigModified.connect(
                [this] (model::IGame const & game) {
                    gameView.notify(game);
                }
            );
        } else {
            exit(0);
        }
    } else if (app.state == model::Application::State::FINISHED) {
		std::cout << "Contract: " << std::endl;
		ui::text::Printer::print(app.getGame().result.contract);
		std::cout << std::endl;
		std::cout << "Tricks collected by declarer and his partner: " 
			<< app.getGame().result.tricksCollected << std::endl;
		std::cout << indent << "Thanks for playing!" << std::endl;
	}
}
