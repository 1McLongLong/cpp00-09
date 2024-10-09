#include "../inc/Character.hpp"


Character::Character() {
  name = "default";
  for (int i = 0; i < 4; i++)
    slots[i] = nullptr;
  std::cout << "Character default constructor is called\n";
}

Character::Character(std::string name) : name(name) {
  for (int i = 0; i < 4; i++)
    slots[i] = nullptr;
  std::cout << "Character default constructor is called\n";
}

Character::Character(const Character &copy) {
  std::cout << "Character Copy constructor called\n";
  *this = copy;
}

Character &Character::operator=(const Character &copy) {
  std::cout << "Character Copy assignment operator called\n";
  if (this != &copy) {
    this->name = copy.name;
  }
  return *this;
}

Character::~Character() {
  std::cout << "Character destructor is called\n";
}

std::string const &Character::getName() const {
  return this->name;
}

void Character::equip(AMateria* m) {
  for (int i = 0; i < 4; i++) {
    if (slots[i] == nullptr) {
      slots[i] = m;
      break;
    }
  }
}

void Character::unequip(int idx) {
  if (idx >= 0 && idx <= 3)
    slots[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target) {
  if ((idx >= 0 && idx <= 3) || slots[idx] == nullptr)
    return ;
  slots[idx]->use(target);
}

// AMateria *Character::getMateria(int i) {
// }





