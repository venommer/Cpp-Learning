#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
	float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
	stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
	return stream;
}

//make sure you passing the reference when you write a function,so that we could avoid copying the entire array.
void Function(const std::vector<Vertex>& vertices)
{

}

/*
* 1. once you resize the vector,it needs to copy all the data and reallocate it,which is a huge performance
* 2. trying to create objects vector if possible instead of pointers,
*	 cause if using objects vector,they will be stored in a row in memory,and once we use it,
*    those objects will be in the same cache line,and it will be mush faster,
*    but if we create pointers vector,the memory will be instact,just the address of pointers keeps changing,
*	 the data is being stored fragmentally,and it will be much slower.
* 3. 
*/
int main()
{
	//if you cant konw the exact size of array,you can use vector which is a dynamic array can automatic adjust size after each modification.
	std::vector<Vertex> vertices;
	vertices.push_back({1,2,3});//we can use intialize list to instantiate an object in the push_back function.
	vertices.push_back({4,5,6});
	Function(vertices);
	/*for (int i = 0; i < vertices.size(); i++)
		std::cout << vertices[i] << std::endl;*/

	for (Vertex v :vertices)//if you dont use reference here,this will copy each vertex object
		std::cout << v << std::endl;

	vertices.erase(vertices.begin() + 1);//the erase function takes in an iterator


	for (Vertex& v : vertices)//so use reference here,this will not going to copy data,and will be much faster.
		std::cout << v << std::endl;

	Vertex vertice = vertices.back();
	std::cin.get();
}