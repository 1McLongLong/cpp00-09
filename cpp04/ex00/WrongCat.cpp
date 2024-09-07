#include "WrongCat.hpp"

WrongCat::WrongCat() : Animal("WrongCat") {
  std::cout << "WrongCat default constructor is called\n";
}

WrongCat::WrongCat(const WrongCat &copy) {
  std::cout << "WrongCat copy constructor constructor is called\n";
  *this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &copy) {
  std::cout << "WrongCat Copy assignment operator called\n";
  if (this != &copy)
  {
    this->type = copy.type;
  }
  return *this;
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat destructor is called\n";
}

void WrongCat::makeSound() const {
  std::cout << "Meow! Meow!\n";
}

