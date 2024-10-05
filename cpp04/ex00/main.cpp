#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/* int main(void) {
  const Animal *meta = new Animal();
  const Animal *i = new Cat();
  const Animal *j = new Dog();
  std::cout << i->getType() << " " << std::endl;
  std::cout << j->getType() << " " << std::endl;
  i->makeSound();  // will output the cat sound!
  j->makeSound();
  meta->makeSound();
  delete meta;
  delete i;
  delete j;
  
  std::cout << "\n";
  
  const Animal *meta2 = new Animal();
  const Cat *i2 = new Cat();
  const Dog *j2 = new Dog();
  std::cout << i2->getType() << " " << std::endl;
  std::cout << j2->getType() << " " << std::endl;
  i2->makeSound();  // will output the cat sound!
  j2->makeSound();
  meta2->makeSound();
  delete meta2;
  delete i2;
  delete j2;

  std::cout << "\n";

  const WrongAnimal *meta3 = new WrongAnimal();
  const WrongAnimal *i3 = new WrongCat();
  std::cout << meta3->getType() << " " << std::endl;
  std::cout << i3->getType() << " " << std::endl;
  meta3->makeSound();
  i3->makeSound();  // makes WrongAnimal sound because makeSound in WrongAnimal
  // is not virtual
  delete meta3;
  delete i3;  // also, only calls one destructor, because destructor of
  // WrongAnimal is not virtual

  return 0;
} */


int main() {
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound();
  j->makeSound();
  meta->makeSound();

  std::cout << j->getType() << " " << std::endl;

  i->makeSound();

  delete meta;
  delete j;
  delete i;

  const WrongAnimal* wrongMeta = new WrongAnimal();
  const WrongAnimal* wrongCat = new WrongCat();

  std::cout << wrongCat->getType() << " " << std::endl;
  wrongCat->makeSound();
  wrongMeta->makeSound();

  delete wrongMeta;
  delete wrongCat;

  return 0;
}

