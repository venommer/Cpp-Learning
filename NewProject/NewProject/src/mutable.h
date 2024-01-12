#pragma once
#include <iostream>
#include  <string>

class Entity
{
private:
	std::string m_Name;
	mutable int m_DebugCount = 0;
public:
	const std::string& GetName() const
	{
		m_DebugCount++; // only mutable varibles can be modified in const functions.
		return m_Name;
	}
};

int main() {
	const Entity e;
	std::string name = e.GetName();

	int x = 8;
	auto f = [=]() mutable
		{
			x++;
			std::cout << x << std::endl;
		};
	f();
	std::cout << name << std::endl;
	std::cin.get();
}