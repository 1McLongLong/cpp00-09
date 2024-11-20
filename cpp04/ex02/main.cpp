#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\n";
	
  std::cout << j->getType() << "\n";
	j->makeSound();
	std::cout << i->getType() << "\n";
	i->makeSound();
	
  std::cout << "\n";

	delete j;
	delete i;
	return (0);
}

