#include "Character.hpp"

Character::Character() : name("default"){
  for (int i = 0; i < 4; i++)
    slots[i] = NULL;
  // std::cout << "Character default constructor is called\n";
}

Character::Character(std::string name) : name(name) {
  for (int i = 0; i < 4; i++)
    slots[i] = NULL;
  // std::cout << "Character default constructor is called\n";
}

Character::Character(const Character &copy) {
  // std::cout << "Character Copy constructor called\n";
  for (int i = 0; i < 4; i++) {
    slots[i] = NULL;
    if(copy.slots[i])
      slots[i] = copy.slots[i]->clone();
  }
}

Character &Character::operator=(const Character &copy) {
  // std::cout << "Character Copy assignment operator called\n";
  if (this != &copy) {
    for (int i = 0; i < 4; i++) {
      delete slots[i];
      slots[i] = NULL;
    }
    for (int i = 0; i < 4; i++) {
      if(copy.slots[i])
        slots[i] = copy.slots[i]->clone();
    }
    this->name = copy.name;
  }
  return *this;
}

Character::~Character() {
  // std::cout << "Character destructor is called\n";
  for (int i = 0; i < 4; i++) {
    if (slots[i] != NULL)
    {
      delete slots[i];
      slots[i] = NULL;
    }
  }
}

std::string const &Character::getName() const {
  return this->name;
}

void Character::equip(AMateria* m) {
  int flag = 0;
  if (!m)
    exit(EXIT_FAILURE);
  for (int i = 0; i < 4; i++) {
    if (slots[i] == m) {
      flag = -1;
      break ;
    }
    if (slots[i] == NULL)
    {
      flag = -1;
      slots[i] = m;
      break ;
    }
  }
  if (!flag)
    delete m;
}

void Character::unequip(int idx) {
  if (idx >= 0 && idx <= 3)
    slots[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
  if ((idx < 0 || idx > 3) || slots[idx] == NULL)
    return ;
  slots[idx]->use(target);
}

