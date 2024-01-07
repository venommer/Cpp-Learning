#pragma once
#include <iostream>
#include  <array>

class Entity
{
public:
	static const int exampleSize = 5;
	int  example[exampleSize];

	std::array<int, 5> another;

	Entity()
	{
		for (int i = 0; i < 5; i++)
		{
			example[i] = 2;
		}
	}
};

int main() {
	int example[5];
	/*
	int* ptr = example;
	for (int i = 0; i < 5; i++)
	{
		example[i] = 2;
	}

	example[2] = 5;
	*(int*)((char*)ptr + 8) = 6;
	std::cout << ptr << std::endl;
	std::cout << ptr + 1 << std::endl;
	*/
	for (int i = 0; i < 5; i++)
	{
		example[i] = 2;
	}
	int* another = new int[5];
	for (int i = 0; i < 5; i++)
	{
		another[i] = 2;
	}
	delete[] another;
	std::cin.get();
}