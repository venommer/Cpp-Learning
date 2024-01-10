#pragma once
#include <iostream>
#include  <string>

/*
always marks your functions as const
if they do not actually modify the varibles
or they are not supposed to modify the varibles!!
*/
class Entity
{
private:
	int m_X, m_Y;
	int* m_X1, * m_Y1;
	/*
	if you want to declare several pointers in one line,
	dont forget to add a asterisk in front of the each varible.
	*/
	mutable int var;
	/*
	the mutable key word means the varible is mutable,
	can also be modified in const functions.
	*/
public:
	//this kind of declaration can only be used in class
	int GetX() const//the cosnt key word means promise not to modify the class members,just gonna read;
	{
		var = 2;
		return m_X;
	}

	void SetX(int x)
	{
		m_X = x;
	}
};
void PrintEntity(const Entity& e)//const reference is the same thing as const pointer;
{
	std::cout << e.GetX() << std::endl;
	/*if the GetX function is not claimed as const,
	there will be an error ,
	cause you cant insure
	there will not be some modifications to class members in that function; */
}

int main() {
	Entity e;
	const int MAX_AGE = 90;

	//int const* a = new int;
	const int* a = new int;//the above two declarations are the same,the data stored in the pointed address is const int,but the pointer can change its pointing address.
	//int* const a = new int;//this means you cant reassign the pointer,but you can modify the data stored inside
	a = &MAX_AGE;
	std::cout << *a << std::endl;
	std::cin.get();
}