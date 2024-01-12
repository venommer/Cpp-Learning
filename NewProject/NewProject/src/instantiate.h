#pragma once
#include <iostream>
#include  <string>

using String = std::string;

class Entity
{
private:
	String m_Name;
public:
	Entity() : m_Name("Unkonwn") {}
	Entity(const String& name) : m_Name(name) {}
	const String& GetName() const { return m_Name; }
};

/*
1.performance allocated on the heap takes longer than on the stack,
and also when you allocated on the heap,
you have to manually free that memory you allocated.
2.when you really have to control the lifetime of objects or you have to instantiate a huge objects,
you should create objects on the heap,
otherwise you should create it on the stack.
*/
int main() {
	//different ways to instantiate objects:
	Entity entity;
	/*
	this will call the non-parameter constructor ,
	and create the objects in stack,
	which means it will be destroyed when out of its scope.
	*/
	Entity entity2("lhw");
	Entity entity3 = Entity("lhw");

	Entity* entity4 = new Entity("lhw");//use new key to create object on the heap,whick means it will not be destroyed unless you free them manually.
	std::cout << (*entity4).GetName() << std::endl;//can also entity->GetName()
	delete entity4;//free the memory that allocated for entity4,once new something,must delete it after or it will lead to memory leak.
	std::cin.get();
}