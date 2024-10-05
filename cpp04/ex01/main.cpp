#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


// void f() {
// 	system("leaks poly");
// }

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	const Animal *animals[4] = {new Dog(), new Dog(), new Cat(), new Cat()};
	for (int i = 0; i < 4; i++)
		animals[i]->makeSound();
	for (int i = 0; i < 4; i++)
		delete animals[i];

	// atexit(f);
	
	return 0;
}
