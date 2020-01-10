
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Started by Jorge Bárcena on December of 2020                               *
*                                                                             *
*  This is free software released into the public domain.                     *
*                                                                             *
*  j.barcenalumbreras@gmail.com                                               *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "headers/Planet2D.hpp"

#define PI   3.1415
#define PI2  2 * PI
#define RAD  PI / 180

using namespace SolarSystem;
using namespace sf;

//Inicializacion de la lista de planetas
std::vector<Planet2D*> Planet2D::instances = {};

/*
* Contructor que recibe los parametros de como va a ser el planeta en cuestion
*/
Planet2D::Planet2D(float _radius, float _angularSpeed, sf::Color _color, Planet2D* _center, float _radiusToCenter = 0, float _translationSpeed = 1, bool _rotationDirectionClock = true, int _vertex = 8) : Model2D({ })
{

    radius                 = _radius;                   // Radio
    vertex                 = _vertex;                   // Numero de vertices
    radiusToCenter         = _radiusToCenter;           // Distancia del punto al que rota
    translationAngle       = 0;                         // Angulo de translacion
    rotationDirectionClock = _rotationDirectionClock;   //Sentido de rotacion
    angular_speed          = _angularSpeed;             //Velocidad de rotacion sobre si misma
    set_color              (  _color                 ); //Color que adopta
    center                 = _center;                   //Centro sobre el que orbita
    translationSpeed       = _translationSpeed;         //Velocidad de translacion

	setListOfPolygons(); // Creamos la esfera basandonos en los vertices


    /* Inicializamos los vertices */

	local_vertices.clear();
	transformed_vertices.clear();

	local_vertices.reserve(spherePoints.size());

	for (auto& point : spherePoints)
	{
		local_vertices.push_back(point);
	}

	transformed_vertices.resize(local_vertices.size());    

	Planet2D::instances.push_back(this); //Añadimos el objeto a la lista de entidades

};

/*
* Divide la esfera en vertices de igual distancia
*/
void Planet2D::setListOfPolygons()
{

	double vertexAngle  = PI2 / vertex;                 // Division de la esfera en X radianes
           spherePoints = {};                           // Puntos de la esfera

	for (int i = 0; i < vertex; ++i)
	{

		float x = cos(vertexAngle * i) * radius;
		float y = sin(vertexAngle * i) * radius;
		spherePoints.push_back(Point3f({ x, y, 1 }));


	}

};

/*
* Divide la esfera de la orbita en vertices de igual distancia
*/
void Planet2D::setListOfOrbit()
{

    if (center != nullptr) //Si no tiene centro sobre el que girar no se calcula su orbita
    {
        float numberOfVertex = radiusToCenter / 2;
        double vertexAngle = PI2 / numberOfVertex;    // Division de la esfera en X radianes

        if(center->center != nullptr || orbitPoints.size() == 0) //Si su padre es un planeta o no se ha calculado la orbita anteriormente
        {
            orbitPoints = {};                             // Puntos de la esfera

            for (int i = 0; i < numberOfVertex; ++i)
            {

                float x = center->position[0] + cos(vertexAngle * i) * radiusToCenter;
                float y = center->position[1] + sin(vertexAngle * i) * radiusToCenter;

                orbitPoints.push_back(Point3f({ x, y, 1 }));


            }
        }
    }
};

/*
* Busca la siguiente posicion del planeta
*/
void Planet2D::update(float delta)
{
	
	if (center != nullptr) //Si no tiene centro sobre el que girar no se culcula su nueva posicion
    {

              translationAngle += translationSpeed * rotationDirectionClock ? 1 : -1; // Angulo actual de translacion
		float vertexAngle       = translationSpeed * translationAngle * RAD;                             // Angulo de tranlacion en radianes 

		float x = center->position[0] + cos(vertexAngle) * radiusToCenter;
		float y = center->position[1] + sin(vertexAngle) * radiusToCenter;

		set_position(x, y); //Ajustamos la posicion
	}

    setListOfOrbit();

	Model2D::update(delta);
};

/*
* Llama a la funcion update() de todos los planetas almacenados
*/
void SolarSystem::Planet2D::renderOrbit(sf::RenderWindow& window)
{

    for (Point3f point : orbitPoints)
    {

        sf::CircleShape shape(1);

        shape.setFillColor(sf::Color(100, 250, 50));
        shape.setPosition(point[0], point[1]);

        window.draw(shape);
       
    }


};


