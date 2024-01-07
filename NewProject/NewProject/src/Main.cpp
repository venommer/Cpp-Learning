#include "visibility.h"

int main() {
	int example[5];
	int* ptr = example;
	for (int i = 0; i < 5; i++)
	{
		example[i] = 2;
	}
	
	example[2] = 5;
	*(int*)((char*)ptr + 8) = 6;
	std::cout << ptr << std::endl;
	std::cout << ptr+1 << std::endl;
	std::cin.get();
}