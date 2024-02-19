#include <iostream>

class Singleton1
{
private:
	static Singleton1* s_instance;
public:
	static Singleton1& Get()
	{
		return *s_instance;
	}

	void Hello() {}
};

Singleton1* Singleton1::s_instance = nullptr;



class Singleton2
{
public:
	static Singleton2& Get()
	{
		static Singleton2 instance;//create singleton instance this way will make our code much cleaner.
		return instance;
	}

	void Hello() {}
};

//lifetime decides how long the varible will exists in memory,scope decides where it can be accessed.
void Function()
{
	int i = 0;//if we call this function,it will always print 1.
	i++;
	std::cout << i << std::endl;
}

void Function2()
{
	static int i = 0;//makes lifetime of the varible lasts in the whole program,but the scope of the varible constrained in the function,can not be accessed outside.
	i++;
	std::cout << i << std::endl;
}

int i = 0;//we can change the lifetime this way,but the scope of the varible is global,can be accessed anywhere,and this is not we want.

int main()
{
	/*Function();
	Function();
	Function();
	Function();
	Function();*/
	Singleton2::Get().Hello();
	std::cin.get();
}