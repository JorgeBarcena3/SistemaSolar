
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

namespace SolarSystem
{

    class Planet2D : public Model2D
    {
        float rotationSpeed; //Velocidad de rotacion

        float radius; //Radio
        
        int vertex; //Numero de vertices

        std::vector< Point3f > * spherePoints;


    public:

        Planet2D(float radius, int _vertex);

        void setListOfPolygons(float radius, int _vertex);
                              
    };

}

#endif