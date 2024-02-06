#pragma once
#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
	float x, y, z;

	Vertex(float x, float y, float z)
		:x(x), y(y), z(z)
	{

	}

	Vertex(const Vertex& vertice)
		:x(vertice.x), y(vertice.y), z(vertice.z)
	{
		std::cout << "Copied!" << std::endl;
	}
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
	stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
	return stream;
}

/*
* once the vector is resized,vector will copy all the data and reallocate them.
* the push_back function construct objects in the main function memory,and copy it to the vector memory,
* so we can optimize the vector in two ways,
* 1. set enough capacity for vector so that its not going to resize
* 2. make the vector construct objects in the memory allocated for vector straightly so that we can avoid copying.
*/
int main()
{
	std::vector<Vertex> vertices;
	//this will construct 3 objects,and it wont through the compile,we should use reserve function just to set capacity and do not have to construct any objects
	//std::vector<Vertex> vertices(3);
	vertices.reserve(3);//set enough capacity

	//we should use emplace_back function which means we tell the vector to construct objects in the vector memory straightly to avoid copying.
	//vertices.push_back(Vertex(1,2,3));

	vertices.emplace_back(1, 2, 3);//just pass the parameters we need to constrct objects,do not have to use intialize list.
	vertices.emplace_back(4, 5, 6);
	vertices.emplace_back(7, 8, 9);
	std::cin.get();
}