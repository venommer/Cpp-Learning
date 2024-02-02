#pragma once
#include <iostream>
#include <memory>

class Entity
{
public:
	void Print() const { std::cout << "Hello!" << std::endl; }
};

class ScopedPtr
{
private:
	Entity* m_Obj;
public:
	ScopedPtr(Entity* entity)
		:m_Obj(entity)
	{

	}

	~ScopedPtr()
	{
		delete m_Obj;
	}

	Entity* operator->()
	{
		return m_Obj;
	}

	const Entity* operator->() const//const version
	{
		return m_Obj;
	}
};

struct Vector3
{
	float x, y, z;
};

int main()
{
	Entity e;
	e.Print();

	Entity* ptr = &e;
	Entity& entity = *ptr;
	ptr->Print();//if the object is a ptr,we can use arrow operator to call member functions and do not have to deference it.


	const ScopedPtr entity1 = new Entity();
	entity1->Print();//so if you want to use arrow operator in a pointer encapsulated in an object,you can overload it.

	//if you want to konw the offset of a serializing data,this is a useful way to do.
	int offset = (int)(&((Vector3*)0)->y);//can also (int)(&((Vector3*)nullptr)->y)
	std::cout << offset << std::endl;
	std::cin.get();
}