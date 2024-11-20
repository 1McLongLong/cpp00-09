#include "Cat.hpp"

Cat::Cat() : Animal("default") {
  type = "Cat";
  std::cout << "Cat default constructor is called\n";
}

Cat::Cat(const Cat &copy) : Animal(copy) {
  std::cout << "Cat copy constructor constructor is called\n";
  *this = copy;
}

Cat &Cat::operator=(const Cat &copy) {
  std::cout << "Cat Copy assignment operator called\n";
  if (this != &copy) {
    Animal::operator=(copy);
  }
  return *this;
}

Cat::~Cat() {
  std::cout << "Cat destructor is called\n";
}

void Cat::makeSound() const {
  std::cout << "Meow! Meow!\n";
}

