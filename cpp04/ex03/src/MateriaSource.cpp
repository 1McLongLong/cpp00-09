#include "../inc/MateriaSource.hpp"


MateriaSource::MateriaSource() {
  std::cout << "MateriaSource default constructor is called\n";
}

MateriaSource::MateriaSource(const MateriaSource &copy) {
  std::cout << "MateriaSource Copy constructor called\n";
  *this = copy;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy) {
  std::cout << "MateriaSource Copy assignment operator called\n";
  if (this != &copy) {
    this->type = copy.type;
  }
  return *this;
}

MateriaSource::~MateriaSource() {
  std::cout << "MateriaSource destructor is called\n";
}



