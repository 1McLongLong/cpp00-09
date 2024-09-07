#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
  std::cout << "Cat default constructor is called\n";
}

Cat::Cat(const Cat &copy) {
  std::cout << "Cat copy constructor constructor is called\n";
  *this = copy;
}

Cat &Cat::operator=(const Cat &copy) {
  std::cout << "Cat Copy assignment operator called\n";
  if (this != &copy)
  {
    this->type = copy.type;
  }
  return *this;
}

Cat::~Cat() {
  std::cout << "Cat destructor is called\n";
}

void Cat::makeSound() const {
  std::cout << "Meow! Meow!\n";
}

