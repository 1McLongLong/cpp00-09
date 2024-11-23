#include "../inc/Character.hpp"

Character::Character() : name("default"), materiaListHead(NULL)  {
  for (int i = 0; i < 4; i++)
    slots[i] = NULL;
  // std::cout << "Character default constructor is called\n";
}

Character::Character(std::string name) : name(name), materiaListHead(NULL) {
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
  clearMateriaList();
}

std::string const &Character::getName() const {
  return this->name;
}

void Character::equip(AMateria* m) {
  if (!m)
    return ;
  for (int i = 0; i < 4; i++) {
    if (this->slots[i] == NULL) {
      if (slots[i] == m) 
        return ;
      slots[i] = m;
      break ;
    }
  }
  MateriaNode* newNode = new MateriaNode(m, materiaListHead);
  materiaListHead = newNode;
}

void Character::unequip(int idx) {
  if (idx >= 0 && idx <= 3)
    slots[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
  if ((idx < 0 || idx > 3) || slots[idx] == NULL)
    return ;
  this->slots[idx]->use(target);
}

void Character::clearMateriaList() {
  MateriaNode* current = materiaListHead;
  while (current != NULL) {
    MateriaNode* temp = current;
    delete current->materia;
    current = current->next;
    delete temp;
  }
  materiaListHead = NULL;
}
