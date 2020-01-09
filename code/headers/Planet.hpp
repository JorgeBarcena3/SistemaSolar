
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Started by Jorge on December of 2020                                       *
*                                                                             *
*  This is free software released into the public domain.                     *
*                                                                             *
*  j.barcenalumbreras@gmail.com                                               *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef PLANET_HEADER
#define PLANET_HEADER

#include "Model2D.hpp"
#include <complex> 


namespace SolarSystem
{

    class Planet2D : public Model2D
    {

	public:

		static std::vector<Planet2D*> instances; //Instancias de los planetas

        float rotationSpeed; //Velocidad de rotacion

        float radius; //Radio
        
        int vertex; //Numero de vertices

        std::vector< Point3f > * spherePoints; //Vertices de la esfera en base con centro en (0,0)

		Planet2D * center; //Centro sobre el que rota

		float radiusToCenter; //Radio desde el centro al que rota a la posicion del planeta

		float translationSpeed; //Velocidad de translacion


    public:

        Planet2D(float radius, Planet2D * center,  int _vertex);

        void setListOfPolygons(float radius, int _vertex);

		void update(float delta);

		/*inline void getTranslationSpeed()*/
		static void nextFrame(float delta)
		{
			for (Planet2D * planet : instances)
			{
				planet->update(delta);
			}
		};

		static void renderNextFrame(sf::RenderWindow& renderer)
		{
			for (Planet2D* planet : instances)
			{
				planet->render(renderer);
			}
		};
                              
    };

}

#endif