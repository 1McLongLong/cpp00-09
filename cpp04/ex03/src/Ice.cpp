#include "../inc/Ice.hpp"

Ice::Ice() : AMateria("default") {
  type = "ice";
  // std::cout << "Ice default constructor is called\n";
}

Ice::Ice(const Ice &copy) : AMateria(copy) {
  // std::cout << "Ice Copy constructor called\n";
  *this = copy;
}

Ice &Ice::operator=(const Ice &copy) {
  // std::cout << "Ice Copy assignment operator called\n";
  if (this != &copy) {
    this->type = copy.type;
  }
  return *this;
}

Ice::~Ice() {
  // std::cout << "Ice destructor is called\n";
}


Ice *Ice::clone() const {
  return new Ice();
}

void Ice::use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
} 

