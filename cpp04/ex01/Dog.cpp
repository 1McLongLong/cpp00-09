#include "Dog.hpp"

Dog::Dog() {
  brain = new Brain();
  type = "Dog";
  std::cout << "Dog default constructor is called\n";
}

Dog::Dog(const Dog &copy) : Animal(copy), brain(new Brain(*copy.brain)){
  std::cout << "Dog copy constructor constructor is called\n";
  this->brain = NULL;
  *this = copy;
}

Dog &Dog::operator=(const Dog &copy) {
  std::cout << "Dog Copy assignment operator called\n";
  if (this != &copy)
  {
    Animal::operator=(copy);
    delete this->brain;
    brain = new Brain(*copy.brain);
    this->type = copy.type;
  }
  return *this;
}

Dog::~Dog() {
  std::cout << "Dog destructor is called\n";
  delete this->brain;
}

void Dog::makeSound() const {
  std::cout << "Woof! Woof!\n";
}

