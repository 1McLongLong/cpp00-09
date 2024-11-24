#include "Cat.hpp"

Cat::Cat() {
  type = "Cat";
  brain = new(std::nothrow) Brain();
  if (brain == NULL)
    exit(EXIT_FAILURE);
  std::cout << "Cat default constructor is called\n";
}

Cat::Cat(const Cat &copy) : Animal(copy) {
  std::cout << "Cat copy constructor constructor is called\n";
  this->brain = new(std::nothrow) Brain(*(copy.brain)); 
  if (brain == NULL)
    exit(EXIT_FAILURE);
}

Cat &Cat::operator=(const Cat &copy) {
  std::cout << "Cat Copy assignment operator called\n";
  if (this != &copy) {
    Animal::operator=(copy);
    delete brain;
    this->brain = new(std::nothrow) Brain(*(copy.brain)); 
    if (brain == NULL)
      exit(EXIT_FAILURE);
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

