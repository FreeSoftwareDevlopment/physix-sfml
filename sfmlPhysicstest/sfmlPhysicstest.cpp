// sfmlPhysicstest.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "sfmlPhysicstest.h"
#include <thread>
#include <iostream>
#include "../deps/Chipmunk2D/include/chipmunk/chipmunk.h"

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
		shape.setOrigin(sf::Vector2f(25, 25));
		shape.setPosition(sf::Vector2f(w / 2, 30));

		p1.setFillColor(sf::Color::Red);

		p1.setOrigin(sf::Vector2f(w, 10));
		p1.setPosition(sf::Vector2f(w - ((w / 2) - 20), h - 30));

		renderthings.push_back(&shape);
		renderthings.push_back(&p1);
	}

	//CHIPMUNK SETUP
	cpVect gravity = cpv(0, 100);
	cpSpace* space = cpSpaceNew();
	cpSpaceSetGravity(space, gravity);
	// Add a static line segment shape for the ground.
 // We'll make it slightly tilted so the ball will roll off.
 // We attach it to a static body to tell Chipmunk it shouldn't be movable.
	cpShape* ground = cpSegmentShapeNew(cpSpaceGetStaticBody(space), cpv(0, h - 50), cpv(w, h - 90), 0);
	cpShapeSetFriction(ground, 1);
	cpSpaceAddShape(space, ground);

	cpFloat radius = 50;
	cpFloat mass = 1;

	cpFloat moment = cpMomentForCircle(mass, 0, radius, cpvzero);

	// The cpSpaceAdd*() functions return the thing that you are adding.
	// It's convenient to create and add an object in one line.
	cpBody* ballBody = cpSpaceAddBody(space, cpBodyNew(mass, moment));
	cpBodySetPosition(ballBody, cpv(w / 2, 30));

	// Now we create the collision shape for the ball.
	// You can create multiple collision shapes that point to the same body.
	// They will all be attached to the body and move around to follow it.
	cpShape* ballShape = cpSpaceAddShape(space, cpCircleShapeNew(ballBody, radius, cpvzero));
	cpShapeSetFriction(ballShape, 0.7);

	cpFloat timeStep = 1.0 / 60.0;

	//CHIPMUNK END

	//DISABLE WINDOW GL CONTEXT, IT SHOULD BE ONLY ACTIVE IN THE RENDER THREAD
	window.setActive(false);

	sleep(1000);

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
		//PHYSIM
		cpVect pos = cpBodyGetPosition(ballBody);
		cpVect vel = cpBodyGetVelocity(ballBody);
		shape.setPosition(sf::Vector2f(pos.x, pos.y));
		printf(
			"Time is %5.2f. ballBody is at (%5.2f, %5.2f). It's velocity is (%5.2f, %5.2f)\n",
			time, pos.x, pos.y, vel.x, vel.y
		);

		cpSpaceStep(space, timeStep);
		//END PHYSIM
		sleep(10);
	}

	// Clean up our physics objects and exit!
	cpShapeFree(ballShape);
	cpBodyFree(ballBody);
	cpShapeFree(ground);
	cpSpaceFree(space);

	//WAIT FOR RENDERER TO CLOSE
	rt.join();
	return 0;
}
