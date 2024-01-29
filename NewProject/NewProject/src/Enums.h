#pragma once
#include <iostream>

/*
* 1. enum is a set of integers
* 2. enum is just a way to group and name some integers when you want to use them to reprensent some certain states.
* 3. the enum type varibles can only be assigned with the value that definited in the type.
*/
enum Example : unsigned char//the default type is integer but if we do not need that much memory,we can make it char,but cant make it float because enum has to be integer.
{
	A, B = 5, C
};