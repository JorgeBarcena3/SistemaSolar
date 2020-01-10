
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Started by Jorge Bárcena on December of 2020                               *
*                                                                             *
*  This is free software released into the public domain.                     *
*                                                                             *
*  j.barcenalumbreras@gmail.com                                               *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#ifndef PLANET_HEADER
#define PLANET_HEADER

#include "Model2D.hpp"
#include <SFML/Graphics.hpp>


using namespace toolkit;

namespace SolarSystem
{

    class Planet2D : public Model2D
    {

    public:

        static std::vector<Planet2D*> instances;              //Instancias de los planetas

        float                         radius;                 //Radio
                                      
        int                           vertex;                 //Numero de vertices
                                      
        std::vector< Point3f >        spherePoints;           //Vertices de la esfera en base con centro en (0,0)

        std::vector< Point3f >        orbitPoints;            //Puntos que se pintaran sobre la orbita
                                      
        Planet2D*                     center;                 //Centro sobre el que rota
                                      
        float                         radiusToCenter;         //Radio desde el centro al que rota a la posicion del planeta
                                      
        float                         translationSpeed;       //Velocidad de translacion
                                                              
        float                         translationAngle;       //Angulo de translacion
                                      
        bool                          rotationDirectionClock; //Si rota en el sentido de las agujas del reloj



    public:

        /*
        * Contructor que recibe los parametros de como va a ser el planeta en cuestion
        */
        Planet2D(
            float     radius,                           //Radio
            float     angularSpeed,                     //Velocidad de giro sobre si mismo
            sf::Color color,                            //Color
            Planet2D* center,                           //Centro sobre el que gira
            float     radiusToCenter,                   //Distancia de ese centro
            float     translationSpeed,                 //Velocidad de translacion
            bool      rotationDirectionClock,           //Direccion
            int       vertex                            //Numero de vertices
        );      

        /*
        * Divide la esfera en vertices de igual distancia
        */
        void setListOfPolygons();

        /*
        * Divide la esfera en vertices de igual distancia
        */
        void setListOfOrbit();
        
        /*
        * Busca la siguiente posicion del planeta
        */
        void update(float delta); 
        

        void set_translationSpeed(float _speed)
        {
            translationSpeed = _speed;
        }

        /*
        * Renderiza la orbita del planeta
        */
        void renderOrbit(sf::RenderWindow& window);

        /*
        * Llama a la funcion update() de todos los planetas almacenados
        */
        static void Update(float delta)
        {
            for (Planet2D* planet : instances)
            {
                planet->update(delta);
            }
        };

        /*
        * Llama a la funcion render() de todos los planetas almacenados
        */
        static void Render(sf::RenderWindow& renderer)
        {
            for (Planet2D* planet : instances)
            {
                planet->renderOrbit(renderer);
                planet->render(renderer);
            }
        };

    };

}

#endif