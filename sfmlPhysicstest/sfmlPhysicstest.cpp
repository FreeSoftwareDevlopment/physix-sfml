// sfmlPhysicstest.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "sfmlPhysicstest.h"
#include <thread>
#include <iostream>

int main()
{
	const int sizeofw[] = { 800, 600 };
#define w (float)sizeofw[0]
#define h (float)sizeofw[1]
	sf::RenderWindow window(sf::VideoMode(sizeofw[0], sizeofw[1]), "PhysX");
	std::vector<sf::Drawable*> renderthings;

	sf::CircleShape shape(50.f);
	sf::RectangleShape p1(sf::Vector2f(w * 2, 20));
	{
		// set the shape color to green
		shape.setFillColor(sf::Color(100, 250, 50));

		p1.setFillColor(sf::Color::Red);

		p1.setOrigin(sf::Vector2f(w, 10));
		p1.setPosition(sf::Vector2f(w - (w / 2), h - 30));

		renderthings.push_back(&shape);
		renderthings.push_back(&p1);
	}

	window.setActive(false);

	sleep(1000);

	std::thread rt(renderingThread, &window, renderthings);

	bool rtv[] = { false, false };
	int r = 0;
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
		rtv[0] = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A);
		rtv[1] = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);
		if (rtv[1] || rtv[0])
			p1.setRotation(r += (rtv[0] ? -1 : 1));
		sleep(60);
	}
	rt.join();
	return 0;
}
