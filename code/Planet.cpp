#include "headers/Planet.hpp"
#include <iostream>

#define PI_M 3.1415

using namespace SolarSystem;

Planet2D::Planet2D(float _radius, int _vertex = 8) : Model2D({ })
{
    setListOfPolygons(_radius, _vertex);

    local_vertices.clear();
    transformed_vertices.clear();

    local_vertices.reserve(spherePoints->size());

    for (auto& point : *spherePoints)
    {
        local_vertices.push_back(point);
    }

    transformed_vertices.resize(local_vertices.size());

};


void SolarSystem::Planet2D::setListOfPolygons(float _radius, int _vertex)
{
    radius = _radius;
    vertex = _vertex;

    float vertexAngle = (2 * PI_M) / _vertex;
    spherePoints = new std::vector< Point3f >();

    Point3f puntoInicial({ position[0], position[1], 1 });

    for (size_t i = 0; i < vertex; ++i)
    {

        float x = cos(vertexAngle * i) * radius;
        float y = sin(vertexAngle * i) * radius;
        spherePoints->push_back(Point3f({ x, y, 1 }));


    }

};

