#include "AMateria.hpp"

AMateria::AMateria() {
  this->type = "default";
  // std::cout << "AMateria default constructor is called\n";
}

AMateria::AMateria(std::string const &type) : type(type) {
  // std::cout << "AMateria default constructor is called\n";
}

AMateria::AMateria(const AMateria &copy) {
  // std::cout << "AMateria Copy constructor called\n";
  *this = copy;
}

AMateria &AMateria::operator=(const AMateria &copy) {
  // std::cout << "AMateria Copy assignment operator called\n";
  if (this != &copy) {
    this->type = copy.type;
  }
  return *this;
}

AMateria::~AMateria() {
  // std::cout << "AMateria destructor is called\n";
}


std::string const &AMateria::getType() const {
  return this->type;
}

void AMateria::use(ICharacter& target) {
  std::cout << "* AMateria used on " << target.getName() << " *\n";
} 

