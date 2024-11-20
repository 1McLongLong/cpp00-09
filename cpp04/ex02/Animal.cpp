#include "Animal.hpp"


Animal::Animal() : type("default") {
  std::cout << "Animal default constructor is called\n";
}

Animal::Animal(std::string type) {
  this->type = type;
  std::cout << "Animal parameterized constructor is called\n";
}

Animal::Animal(const Animal &copy) {
  std::cout << "Animal Copy constructor called\n";
  *this = copy;
}

Animal &Animal::operator=(const Animal &copy) {
  std::cout << "Animal Copy assignment operator called\n";
  if (this != &copy) {
    this->type = copy.type;
  }
  return *this;
}

Animal::~Animal() {
  std::cout << "Animal destructor is called\n";
}

std::string Animal::getType() const {
  return this->type;
}

