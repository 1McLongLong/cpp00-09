#include "Cat.hpp"

Cat::Cat() : Animal("default") {
  type = "Cat";
  brain = new Brain();
  std::cout << "Cat default constructor is called\n";
}

Cat::Cat(const Cat &copy) : Animal(copy) {
  std::cout << "Cat copy constructor constructor is called\n";
  this->type = copy.type;
  this->brain = new Brain();
  *brain = *(copy.brain);
}

Cat &Cat::operator=(const Cat &copy) {
  std::cout << "Cat Copy assignment operator called\n";
  if (this != &copy) {
    Animal::operator=(copy);
    delete brain;
    this->brain = new Brain();
    *brain = *(copy.brain);
  }
  return *this;
}

Cat::~Cat() {
  std::cout << "Cat destructor is called\n";
  delete brain;
}

void Cat::makeSound() const {
  std::cout << "Meow! Meow!\n";
}

