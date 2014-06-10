#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <memory>
#include "ui/Observable.hpp"
#include "ui/text/Printer.hpp"
#include "model/DummyComputerPlayer.hpp"
#include "model/Game.hpp"

namespace model
{

class Application : public ui::Observable<Application>
{
    
public:
	enum State {
		INITIAL, STARTED, FINISHED
	};

	State state;

    Application() : state(INITIAL) {}
    void run();

	model::IGame const & getGame() const {
		if (game) {
			return *game;
		}
		throw std::logic_error("Game has not yet been initialized");
	}

private:
	std::unique_ptr<model::IGame> game;
};

} // namespace model

#endif // APPLICATION_HPP
