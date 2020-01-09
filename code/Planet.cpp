#include "headers/Planet.hpp"
#include <iostream>

#define PI_M 3.1415

using namespace SolarSystem;

std::vector<Planet2D*> Planet2D::instances = {};

Planet2D::Planet2D(float _radius, Planet2D* _center, int _vertex = 8) : Model2D({ })
{
	setListOfPolygons(_radius, _vertex);

	center = _center;

	local_vertices.clear();
	transformed_vertices.clear();

	local_vertices.reserve(spherePoints->size());

	for (auto& point : *spherePoints)
	{
		local_vertices.push_back(point);
	}

	transformed_vertices.resize(local_vertices.size());

	lastAngle = 0;

	Planet2D::instances.push_back(this);

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


void SolarSystem::Planet2D::update(float delta)
{
	radiusToCenter = center != nullptr ? (
		200//sqrt(pow((position[0] - center->position[0]), 2) + pow((position[1] - center->position[1]), 2))
		) : 0;

	if (center != nullptr)
	{

		//Vector2f PQ({ (position[0] - center->position[0]) , (position[1] - center->position[1]) });
		//float length = sqrt(pow(PQ[0], 2) + pow(PQ[1], 2));

		angle += 1;

		float vertexAngle = angle * (PI_M / 180);

		float x = center->position[0] + cos(vertexAngle) * 200;
		float y = center->position[1] + sin(vertexAngle) * 200;

		set_position(x, y);
	}
	//set_position(x._Val, y.val);


	Model2D::update(delta);
};

