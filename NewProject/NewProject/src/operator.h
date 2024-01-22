#pragma once
#include <iostream>
#include  <string>

using String = std::string;

struct Vector2
{
	float x, y;

	Vector2(float x, float y)
		: x(x), y(y) {}

	Vector2 Add(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 operator+(const Vector2& other) const
	{
		return Add(other);
	}

	Vector2 Multiply(const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}

	Vector2 operator*(const Vector2& other) const
	{
		return Multiply(other);
	}

	bool operator==(const Vector2& other) const
	{
		return x == other.x && y == other.y;
	}

	bool operator!=(const Vector2& other) const
	{
		//return !operator==(other);
		return !(*this == other);//the above annotation code is weird,use this way or get a equals function and return it.
	}
};

std::ostream& operator<<(std::ostream& stream, const Vector2& other)
{
	stream << other.x << "," << other.y;
	return stream;
}

//operator overload is mainly used to simplify the code.
int main() {
	Vector2 position(4.0f, 4.0f);
	Vector2 speed(0.5f, 1.5f);
	Vector2 powerup(1.1f, 1.1f);

	Vector2 result1 = position.Add(speed.Multiply(powerup));//hard to read.
	Vector2 result2 = position + speed * powerup;//overload the operator to make the code cleaner.
	if (result1 == result2)//overload == to make the two vector2 can be compared straightly.
	{

	}
	std::cout << "result1.x: " << result1.x << " result1.y: " << result1.y << std::endl;
	std::cout << "result2.x: " << result2.x << " result2.y: " << result2.y << std::endl;
	std::cout << result2;//overload "<<" to make it print Vector straightly.
	std::cin.get();
}