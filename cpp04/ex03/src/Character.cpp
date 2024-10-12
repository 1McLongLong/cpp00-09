#include "../inc/Character.hpp"

Character::Character() {
  name = "default";
  for (int i = 0; i < 4; i++)
    slots[i] = nullptr;
  // std::cout << "Character default constructor is called\n";
}

Character::Character(std::string name) : name(name) {
  for (int i = 0; i < 4; i++)
    slots[i] = nullptr;
  // std::cout << "Character default constructor is called\n";
}

Character::Character(const Character &copy) {
  // std::cout << "Character Copy constructor called\n";
  // for (int i = 0; i < 4; i++) {
  //   if(this->slots[i])
  //     this->slots[i] = copy.slots[i]->clone();
  // }
  *this = copy;
}

Character &Character::operator=(const Character &copy) {
  // std::cout << "Character Copy assignment operator called\n";
  if (this != &copy) {
  for (int i = 0; i < 4; i++) {
    if(this->slots[i])
      this->slots[i] = copy.slots[i]->clone();
    }
    this->name = copy.name;
  }
  return *this;
}

Character::~Character() {
  // std::cout << "Character destructor is called\n";
  for (int i = 0; i < 4; i++)
  {
    delete slots[i];
  }
}

std::string const &Character::getName() const {
  return this->name;
}

void Character::equip(AMateria* m) {
  for (int i = 0; i < 4; i++) {
    if (this->slots[i] == nullptr) {
      this->slots[i] = m;
			// std::cout << this->name << " equips " << m->getType() << " in " << i << std::endl;
      break;
    }
  }
}

void Character::unequip(int idx) {
  if (idx >= 0 && idx <= 3)
    slots[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target) {
  if ((idx < 0 && idx > 3) || slots[idx] == nullptr)
    return ;
  this->slots[idx]->use(target);
}



