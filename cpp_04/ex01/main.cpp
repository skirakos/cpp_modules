#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
return 0;
}
// int main() {
//     const int size = 4;
//     Animal* animals[size];
    
//     for (int i = 0; i < size / 2; ++i) {
//         animals[i] = new Dog();
//     }
//     for (int i = size / 2; i < size; ++i) {
//         animals[i] = new Cat();
//     }
    
//     std::cout << "\nTesting deep copy:" << std::endl;
//     Dog originalDog;
//     originalDog.makeSound();
//     Dog copiedDog = originalDog; // Calls copy constructor
//     copiedDog.makeSound();
    
//     std::cout << "\nCleaning up..." << std::endl;
//     for (int i = 0; i < size; ++i) {
//         delete animals[i];
//     }
    
//     return 0;
// }