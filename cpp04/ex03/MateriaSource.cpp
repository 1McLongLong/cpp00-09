#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
  for (int i = 0; i < 4; i++)
    slots[i] = NULL;
  // std::cout << "MateriaSource default constructor is called\n";
}

MateriaSource::MateriaSource(const MateriaSource &copy) {
  // std::cout << "MateriaSource Copy constructor called\n";
  *this = copy;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy) {
  // std::cout << "MateriaSource Copy assignment operator called\n";
  if (this != &copy) {
  for (int i = 0; i < 4; i++) {
    if(this->slots[i])
      this->slots[i] = copy.slots[i];
    }
  }
  return *this;
}

MateriaSource::~MateriaSource() {
  // std::cout << "MateriaSource destructor is called\n";
  for (int i = 0; i < 4; i++)
  {
    if (slots[i] != NULL)
    {
      delete slots[i];
      slots[i] = NULL;
    }
  }
}

void MateriaSource::learnMateria(AMateria *m) {
  int flag = 0;
  for (int i = 0; i < 4; i++) {
    if (slots[i] == m)
      return ;
  }
  for (int i = 0; i < 4; i++) {
    if (slots[i] == NULL) 
    {
      flag = -1;
      slots[i] = m;
      return ;
    }
  }
  if (!flag)
    delete m;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  for (int i = 0; i < 4; i++) {
    if (slots[i] != NULL && slots[i]->getType() == type)
      return slots[i]->clone();
  }
  return NULL;
}

