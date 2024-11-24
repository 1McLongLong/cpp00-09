#include "Dog.hpp"

Dog::Dog() {
  type = "Dog";
  brain = new Brain();
  std::cout << "Dog default constructor is called\n";
}

Dog::Dog(const Dog &copy) : Animal(copy) {
  std::cout << "Dog copy constructor constructor is called\n";
  this->brain = new Brain(*(copy.brain));
}

Dog &Dog::operator=(const Dog &copy) {
  std::cout << "Dog Copy assignment operator called\n";
  if (this != &copy) {
    Animal::operator=(copy);
    delete brain;
    this->brain = new Brain(*(copy.brain));
  }
  return *this;
}

Dog::~Dog() {
  delete brain;
  std::cout << "Dog destructor is called\n";
}

void Dog::makeSound() const {
  std::cout << "Woof! Woof!\n";
}

