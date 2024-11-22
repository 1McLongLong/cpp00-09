#include "Cat.hpp"

Cat::Cat() {
  type = "Cat";
  brain = new Brain();
  std::cout << "Cat default constructor is called\n";
}

Cat::Cat(const Cat &copy) : Animal(copy) {
  std::cout << "Cat Copy constructor constructor is called\n";
  this->type = copy.type;
  this->brain = new Brain(*(copy.brain));
}

Cat &Cat::operator=(const Cat &copy) {
  std::cout << "Cat Copy assignment operator called\n";
  if (this != &copy) {
    Animal::operator=(copy);
    delete brain;
    this->brain = new Brain(*(copy.brain));
  }
  return *this;
}

Cat::~Cat() {
  delete brain;
  std::cout << "Cat destructor is called\n";
}

void Cat::makeSound() const {
  std::cout << "Meow! Meow!\n";
}

