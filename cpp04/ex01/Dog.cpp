#include "Dog.hpp"

Dog::Dog() {
  type = "Dog";
  brain = new(std::nothrow) Brain();  
  if (brain == NULL)
    exit(EXIT_FAILURE);
  std::cout << "Dog default constructor is called\n";
}

Dog::Dog(const Dog &copy) {
  std::cout << "Dog copy constructor constructor is called\n";
  this->brain = new(std::nothrow) Brain(*(copy.brain));  
  if (brain == NULL)
    exit(EXIT_FAILURE);
}

Dog &Dog::operator=(const Dog &copy) {
  std::cout << "Dog Copy assignment operator called\n";
  if (this != &copy) {
    Animal::operator=(copy);
    delete brain;
    this->brain = new(std::nothrow) Brain(*(copy.brain)); 
    if (brain == NULL)
      exit(EXIT_FAILURE);
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

