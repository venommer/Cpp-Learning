#include <iostream>
#include  <string>

/*
we should konw this is a pointer point to the current instance,
so (*this) is the current object.
*/

class Entity
{
public:
	int x, y;
	Entity(int x, int y)
	{
		Entity* e = this; //thats the actual type of this .
		Entity* const& e1 = this;//if you want to create a reference of this,have to add a const before ampersand.
		e1->x = x;
		e1->y = y;
		this->x = x;//this is the common way to use 'this'.
		(*this).x = x;//bairly used.
		PrintEntity(this);
	}

	int GetX() const//dont forget the const cause we dont modify the members at all.
	{
		const Entity* e = this;//thats the actual type of 'this' in the const member function.
		return this->x;
	}
};

void PrintEntity(Entity* e)
{
	//print
}
int main() {
	
	std::cin.get();
}