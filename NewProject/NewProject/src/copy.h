#pragma once
#include <iostream>
#include <memory>

class String
{
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	String(const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1];//strcpy includes the null termination character
		memcpy(m_Buffer, string, m_Size + 1);
		m_Buffer[m_Size] = 0;//make sure the string has a null termination character.
	}

	//actually c++ offer you default copy constructor,which indeed just use memcpy to copy everything inside.
	String(const String& other)
		:m_Size(other.m_Size)
	{
		std::cout << "Copied String!" << std::endl;
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
	}

	friend std::ostream& operator<<(std::ostream& stream, const String& string);

	~String()
	{
		delete[] m_Buffer;
	}

	char& operator[](unsigned int index)
	{
		//safety check
		return m_Buffer[index];
	}
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer;//can also write a GetBuffer function.
	return stream;
}

//always pass your objects as const reference,if you want to copy the object,you can copy inside the function,there is no need to copy object when passing it.
void PrintString(const String& string)
{
	std::cout << string << std::endl;
}

int main()
{
	String string = "Cherno";
	String second = string;//this copy makes the two pointers points two the same memory.

	string[2] = 'a';
	//std::cout << string << std::endl;
	//std::cout << second << std::endl;

	PrintString(string);
	PrintString(second);

	std::cin.get();
}//if you dont overwrite the copy constructor to allocate another block memory for second Strig,when the main function ends,execute two destructors,they all have to delete the pointer,but they point to the same place,so that memory will be freed twice,and thats a fatal error.