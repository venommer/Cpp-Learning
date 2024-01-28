#pragma once
#include <iostream>
#include  <string>
#include <memory>


class Entity
{
public:
	Entity()
	{
		std::cout << "Created Entity!" << std::endl;
	}

	~Entity()
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}
};

/*
1. unique_ptr first preference,shared_ptr second preference
2. unique_ptr has very low overhead,so when you can use unique_ptr,just use it.
3. shared_ptr use reference counting to track the reference of this ptr,when the count reachs 0,the shared_ptr will be destroyed.
4. because of the reference counting,shared_ptr has a lot of overhead

*/
int main()
{
	{
		std::shared_ptr<Entity> e1;
		{
			/*
			can also sharedEntity(new Entity()), but never use it that way,
			cause shared_ptr has to allocate two block of memory,
			one for the pointer ,another for the control block which implements reference counting.
			so if you first create a new Entity and pass it to the shared_ptr constructor,
			there will be two allocations,
			first for Entity,second for control block,
			but if you use make_shared,
			they can be constructed together which is way more efficient.
			*/
			std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
			e1 = sharedEntity;

			//weak_ptr copy the sharedEntity but not increase the reference count.
			//through weak_ptr we can konw about the situation of shared_ptr,but weak_ptr wont keep the shared_ptr alive! 
			std::weak_ptr<Entity> weakEntity = sharedEntity;


			//have to call the unique_ptr constructor explicitly cause the implementation use explicit keyword.
			//unique_ptr is a stack allocated object,when this objects out of scope,it will call descructor and delete your pointer free that memory.
			std::unique_ptr<Entity> entity = std::make_unique<Entity>();//can also entity(new Entity()),but this is the common way,its safer for exception.
			std::unique_ptr<Entity> e0 = entity;//unique__ptr cant be copied,because the copy constructor and copy assignment operator of unique_ptr are deleted.
		}
	}


	std::cin.get();
}