#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
  const Animal *meta = new Animal();
  const Animal *i = new Cat();
  const Animal *j = new Dog();
  std::cout << i->get_type() << " " << std::endl;
  std::cout << j->get_type() << " " << std::endl;
  i->makeSound();  // will output the cat sound!
  j->makeSound();
  meta->makeSound();
  delete meta;
  delete i;
  delete j;

  const Animal *meta2 = new Animal();
  const Cat *i2 = new Cat();
  const Dog *j2 = new Dog();
  std::cout << i2->get_type() << " " << std::endl;
  std::cout << j2->get_type() << " " << std::endl;
  i2->makeSound();  // will output the cat sound!
  j2->makeSound();
  meta2->makeSound();
  delete meta2;
  delete i2;
  delete j2;

  const WrongAnimal *meta3 = new WrongAnimal();
  const WrongAnimal *i3 = new WrongCat();
  std::cout << meta3->get_type() << " " << std::endl;
  std::cout << i3->get_type() << " " << std::endl;
  meta3->makeSound();
  i3->makeSound();  // makes WrongAnimal sound because makeSound in WrongAnimal
                    // is not virtual
  delete meta3;
  delete i3;  // also, only calls one destructor, because destructor of
              // WrongAnimal is not virtual

  return 0;
}
