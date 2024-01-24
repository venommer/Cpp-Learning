#pragma once
#include <iostream>
#include  <string>


class Entity
{
public:
	Entity()
	{
		std::cout << "Created Entity!" << std::endl;
	}

	~Entity()
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}
};

/*
thats basically how smart pointer works,
using an class as the wrapper of the pointer,
when the class is out of scope,
automatically call the destructor to delete the pointer.
*/
class ScopedPtr
{
private:
	Entity* m_Ptr;
public:
	ScopedPtr(Entity* ptr)
		:m_Ptr(ptr)
	{

	}

	~ScopedPtr()
	{
		delete m_Ptr;
	}
};

/*
this is classic mistake,
cause the array is being created on the stack of CreateArray function,
which means it will be destroyed when the function is being executed,
the array will be no longer exist,
and the memory you allocated for the array is actually be freed,
so this block of memory can be used for operating system,
the operating system can allocate it for other things,
but you still consider it as your array,
its gonna be very dangerous and unsafe to do so.
if you want to create it in that way,
create it on the heap use new keyword.
*/
int* CreateArray()
{
	int array[50];//int* array = new int[50];
	return array;
}

int main() {
	int* b = new int[50];
	int* a = CreateArray();
	/*for (int i = 0; i < 50; i++)
	{
		b[i] = 0;
		a[i] = 0;
	}*/

	std::cout << *(a + 49) << std::endl;
	std::cout << *(b + 50) << std::endl;//normal array dont have the ability to check the array boundary!
	{
		//Entity e;//this is created on the stack,so it will be destroyed automatically when out of its scope.
		Entity* e1 = new Entity();//this is created on the heap,so it wont be destroyed unless you call delete to free the memory.
		ScopedPtr e = new Entity();
	}
	std::cin.get();
}