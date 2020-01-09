
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *  Started by Ángel on november of 2017                                       *
 *                                                                             *
 *  This is free software released into the public domain.                     *
 *                                                                             *
 *  angel.rodriguez@esne.edu                                                   *
 *                                                                             *
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "headers/Planet.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace SolarSystem;

int main()
{
	RenderWindow window(VideoMode(800, 600), "Animation Examples: Transformations", sf::Style::Default, ContextSettings(32));

	window.setVerticalSyncEnabled(true);

	bool running = true;

	Planet2D * Sol = new Planet2D(100, nullptr, 16);
	Sol->set_position(400, 300);

	Planet2D * tierra = new Planet2D(50, Sol, 16);
	tierra->set_position(600, 300);
	tierra->rotationSpeed = (1);
	

	do
	{
		// Process window events:

		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				running = false;
			}
		}

		Planet2D::nextFrame(0);

		// Render:

		window.clear();

		Planet2D::renderNextFrame(window);

		window.display();
	} while (running);

	return EXIT_SUCCESS;
}
