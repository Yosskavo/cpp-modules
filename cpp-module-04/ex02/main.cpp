#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main(void)
{
	Animal *testB = new Dog();
	Animal *testA = new Cat();

	std::cout << testA->getType() << std::endl;
	std::cout << testB->getType() << std::endl;
	testA->makeSound();
	testB->makeSound();
	delete testB;
	delete testA;
}
