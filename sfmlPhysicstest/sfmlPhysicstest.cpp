// sfmlPhysicstest.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "sfmlPhysicstest.h"
#include <thread>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "PhysX");
	std::vector<sf::Drawable*> renderthings;

	sf::CircleShape shape(50.f);
	{
		// set the shape color to green
		shape.setFillColor(sf::Color(100, 250, 50));
		renderthings.push_back(&shape);
	}

	window.setActive(false);

	std::this_thread::sleep_for(std::chrono::milliseconds(2000));

	std::thread rt(renderingThread, &window, renderthings);

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//LOGIC
	}
	rt.join();
	return 0;
}
