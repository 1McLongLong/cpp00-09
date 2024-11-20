#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongDefault") {
  std::cout << "WrongAnimal default constructor is called\n";
}

WrongAnimal::WrongAnimal(std::string type) {
  this->type = type;
  std::cout << "WrongAnimal parameterized constructor is called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
  std::cout << "WrongAnimal Copy constructor called\n";
  *this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy) {
  std::cout << "WrongAnimal Copy assignment operator called\n";
  if (this != &copy) {
    this->type = copy.type;
  }
  return *this;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destructor is called\n";
}

std::string WrongAnimal::getType() const {
  return this->type;
}

void WrongAnimal::makeSound() const {
  std::cout << "An WrongDefault Animal doesn't make sounds\n";
}

