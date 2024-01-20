#pragma once
#include <iostream>
#include  <string>

//string intrinsically is const char[] not char[]
//use const to insure that the string being transfered will not be changed
void PrintString(const std::string& string)//transfer the reference will be faster because if you dont use reference it will copy the original string and allocate extra memory from heap;
{
	std::cout << string << std::endl;
}

/*
int main() {
	const char* name = "Cherno";
	std::string name1 = std::string("lhw") + "hello";
	name1 += "hello"; //stdstring allow us to use += to append string
	char name2[7] = { 'C','h','e','r','n','o','\0' };//this is actually how string works every element is character with the last char "\0" which means null in ASCII;
	std::cout << name1 << std::endl;
	std::cin.get();
}
*/
