#include "../inc/Cure.hpp"

Cure::Cure() {
  type = "cure";
  // std::cout << "Cure default constructor is called\n";
}

Cure::Cure(const Cure &copy) : AMateria(copy) {
  // std::cout << "Cure Copy constructor called\n";
  *this = copy;
}

Cure &Cure::operator=(const Cure &copy) {
  // std::cout << "Cure Copy assignment operator called\n";
  if (this != &copy) {
    this->type = copy.type;
  }
  return *this;
}

Cure::~Cure() {
  // std::cout << "Cure destructor is called\n";
}

Cure *Cure::clone() const {
  return new Cure();
}

void Cure::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "'s wounds *\n";
} 

