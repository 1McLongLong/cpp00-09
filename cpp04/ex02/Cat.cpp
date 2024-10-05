#include "Cat.hpp"

Cat::Cat() {
  brain = new Brain(); 
  type = "Cat";
  std::cout << "Cat default constructor is called\n";
}

Cat::Cat(const Cat &copy) : Animal(copy), brain(new Brain(*copy.brain)){
  std::cout << "Cat copy constructor constructor is called\n";
  this->brain = NULL;
  *this = copy;
}

Cat &Cat::operator=(const Cat &copy) {
  std::cout << "Cat Copy assignment operator called\n";
  if (this != &copy)
  {
    Animal::operator=(copy);
    delete this->brain;
    brain = new Brain(*copy.brain);
    this->type = copy.type;
  }
  return *this;
}

Cat::~Cat() {
  std::cout << "Cat destructor is called\n";
  delete this->brain;
}

void Cat::makeSound() const {
  std::cout << "Meow! Meow!\n";
}

