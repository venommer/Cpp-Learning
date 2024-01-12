#include <iostream>
#include  <string>

/*
member initializer list is the default and first function that will be called in the initialization,
no matter you use it or not,
so you should use it whenever you need to initialize.
*/
class Example
{
public:
	Example()
	{
		std::cout << "Created Entity!" << std::endl;
	}

	Example(int x)
	{
		std::cout << "Created with " << x << "!" << std::endl;
	}
};

class Entity
{
private:
	std::string m_Name;
	int m_Score;
	Example m_example;
public:
	Entity()
		:m_Name("Unkonwn"), m_Score(0),m_example(8)//must initialize the members in the difination order;
	{
		//m_Name = "Unkonwn"; //normal way to intialize,
		//m_example = Example(8);
		/*
		if you do not use initializer list to intialize the class type member,
		this will intialize m_example twice,
		first time call the nonparameter constructor,
		second time call constructor with the parameter 8,
		and just throw away the first object,
		this will lead to some performance waste,
		if use initializer list ,
		it will just initialize once.
		*/
	}

	Entity(const std::string& name)
		: m_Name(name)
	{

	}
};

int main() {
	Entity e;
	
	std::cin.get();
}