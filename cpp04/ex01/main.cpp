#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


void f() {
	system("leaks poly");
}

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

  std::cout << '\n';

  delete j;
  delete i;

  std::cout << '\n';

  const Animal *animals[4] = {new Dog(), new Dog(), new Cat(), new Cat()};

  std::cout << '\n';

  for (int i = 0; i < 4; i++)
    animals[i]->makeSound();

  std::cout << '\n';

  for (int i = 0; i < 4; i++)
    delete animals[i];

  std::cout << '\n';

  // atexit(f);

  return 0;
}
