#include "./sfmlPhysicstest.h"

void renderingThread(sf::RenderWindow* window, std::vector<sf::Drawable*>& renderthings) {
	window->setActive(true);

	window->setFramerateLimit(420);

	while (window->isOpen()) {
		// clear the window with black color
		window->clear(sf::Color::Black);

		// draw everything here...
		// window.draw(...);
		for (unsigned int x{ 0 }; x < renderthings.size(); x++) {
			window->draw(*renderthings[x]);
		}

		// end the current frame
		window->display();
	}
}
