
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *  Started by Ángel on november of 2017                                       *
 *  Modified by Jorge Bárcena on December of 2020                              *
 *                                                                             *
 *  This is free software released into the public domain.                     *
 *                                                                             *
 *  angel.rodriguez@esne.edu                                                   *
 *  j.barcenalumbreras@gmail.com                                               *

 *                                                                             *
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "headers/Planet2D.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace SolarSystem;

int main()
{
	RenderWindow window(VideoMode(800, 600), "Animation Examples: Transformations", sf::Style::Default, ContextSettings(32));

	window.setVerticalSyncEnabled(true);

	bool running = true;

	Planet2D * Sol = new Planet2D(25, 1, sf::Color::Yellow, nullptr, 0, 0, false, 16);
	Sol->set_position(400, 300);

	Planet2D * mercurio = new Planet2D(13, 1.0f, sf::Color(101, 067, 033),      Sol, 075, 1.0f,  true, 16);
	Planet2D * venus    = new Planet2D(22, 0.8f, sf::Color(255, 229, 153),      Sol, 100, 0.8f,  false, 16);
    Planet2D * tierra   = new Planet2D(23, 0.6f, sf::Color(111, 168, 220),      Sol, 200, 0.6f,  true, 16);
    Planet2D * luna     = new Planet2D( 8, 0.6f, sf::Color(153, 153, 153),   tierra,  40, 0.6f,  true, 16);
	Planet2D * marte    = new Planet2D(16, 0.4f, sf::Color(224, 102, 102),      Sol, 270, 0.4f,  true, 16);
	Planet2D * fobos    = new Planet2D(05, 0.1f, sf::Color(153, 153, 153),    marte, 027, 0.8f,  true, 16);
	Planet2D * deimos   = new Planet2D(05, 0.1f, sf::Color(153, 153, 153),    marte,  35, 0.5f, false, 16);
	

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

		Planet2D::Update(0);

		// Render:

		window.clear();

		Planet2D::Render(window);    

		window.display();

	} while (running);

    for (auto planet : Planet2D::instances)
    {
        delete planet;
    }
    
	return EXIT_SUCCESS;
}
