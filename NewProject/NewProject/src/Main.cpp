#include <iostream>
#include  <string>

using String = std::string;

class Entity
{
private:
	String m_Name;
	int m_age;
public:
	Entity() :m_Name("Unkonwn") { std::cout << "Constructor be called!" << std::endl; }
	Entity(const String& name) : m_Name(name),m_age(-1) {}

	/*
	the explicit key word can be used in front of a Constructor,
	which means you can not do the implicit conversion,
	you have to call the function explicitly.
	when you have to ensure your program safe and the computer wont convert the varible into wrong type,
	use this key word.
	*/
	explicit Entity(int age) : m_Name("Unknown"), m_age(age) {}
};

void PrintEntity(const Entity& entity)
{
	//Print
}

int main() {
	/*
	22 can be converted into an entity object,
	because we have an Constructor take integer parameter,
	so the c++ can do the implicit conversion for us;
	*/
	PrintEntity(22);
	/*
	but "Lhw" can not be converted into Entity immediately,
	because Lhw is const char[] type,
	and we only have a std::string type Constructor,
	so we have to convert const char[] into std::string first,
	then we can call the constructor to convert the string into an entity,
	however c++ can only do implicit conversion once at the same time,
	so this wont work.
	*/
	PrintEntity("Lhw");
	PrintEntity((Entity)"Lhw");
	PrintEntity((String)"Lhw");
	Entity a("Lhw");
	Entity a1 = "Lhw";//the same reason as the above PrintEntity function.
	Entity a2 = (String)"Lhw";
	Entity b(22); // better to write in this way,cleaner and understandable.
	std::cin.get();
}