#pragma once
#include <iostream>
#include  <string>

using String = std::string;

class Entity
{
private:
	String m_Name;
public:
	Entity() :m_Name("Unkonwn") { std::cout << "Constructor be called!" << std::endl; }
	/*
	(const String&) transfer the reference of string
	instead of creating a copy
	which makes it faster,high performance,
	so when you have to manipulate string varibles,
	use string&,
	if you do not want it to be modified,
	use const string&¡£
	*/
	Entity(const String& name) : m_Name(name) {}
	const String& GetName() const { return m_Name; }
};

/*
1.new has to search the free block list (which maintains by the system)
to find a block that accommodate your need
and return a pointer that points to it.
2.new is an operator which means we can overload it.
3.usually calling new will call the underlying state C function malloc() which for memory allocate
4.whenever use new remember to use delete to free the memory that allocated,
delete also call the destructor and its a operator too,so it can be overloaded;
*/
int main() {
	int a = 2;
	int* b = new int;//new returns a pointer;
	int* b1 = new int[50];//allocate memory for array;
	Entity* e = new Entity[50];//new keyword not only just allocate memory but also call the constructor
	malloc(50);
	delete e;
	delete[] b1;//if you allocate using new square brackets,you should using delete square brackets;a
	std::cin.get();
}