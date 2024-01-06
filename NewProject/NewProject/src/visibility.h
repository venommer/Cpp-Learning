#pragma once
#include <iostream>
#include <string>

class Entity
{
public://protected: //can be used straghtly in subclass//  private: //cant be used straghtly in subclass or main function,can only be used in the class itself and its friend class
	int X, Y;
	void Print() {}
public:
	Entity() 
	{
		X = 0;
		Print();
	}
};

class Player : public Entity 
{
public:
	Player()
	{
		X = 2;
		Print();
	}
};

/*
#include "visibility.h"

int main() {
	Entity e;
	e.Print();
	e.X = 2;

	std::cin.get();
}
*/