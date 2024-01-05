#include "virtual-function.h"

int main() {
	Entity* e = new Entity();
	PrintName(e);

	Player* p = new Player("Lhw");
	PrintName(p);

	std::cin.get();
}