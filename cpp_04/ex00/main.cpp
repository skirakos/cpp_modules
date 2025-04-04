#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Cat cat;
	Animal* obj = new Cat();

	obj->makeSound();
	return 0;
}