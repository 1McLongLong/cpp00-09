#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hit_points(10), energy_points(10), attack_damage(0) 
{}

ClapTrap::ClapTrap(std::string name) {
  this->name = name;
  this->hit_points = 10;
  this->energy_points = 10;
  this->attack_damage = 0;
  std::cout << "ClapTrap is IN\n";
}


ClapTrap::ClapTrap(const ClapTrap &copy) {
  std::cout << "Copy constructor called\n";
  *this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy) {
  std::cout << "Copy assignment operator called\n";
  if (this != &copy)
  {
    this->name = copy.name;
    this->hit_points = copy.hit_points;
    this->energy_points = copy.energy_points;
    this->attack_damage = copy.attack_damage;
  }
  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap is OUT\n";
}

void ClapTrap::attack(const std::string& target) {
  if (hit_points <= 0 || energy_points <= 0)
    std::cout << "ClapTrap can't attack anymore unfortunately\n";
  else {
    energy_points--;
    std::cout << "ClapTrap " << name << " attacks " 
            << target << ", causing " << attack_damage 
            << " points of damage!\n";
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (hit_points > 0) {
    hit_points -= amount;
    std::cout << "ClapTrap is taking " << amount << " points out of him\n";
  }
  else 
    std::cout << "ClapTrap is out of hit_points\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (energy_points > 0 && hit_points > 0) {
    hit_points += amount;
    energy_points--;
    std::cout << "ClapTrap's aura is gaining " << amount << " points\n";
  }
  else 
    std::cout << "ClapTrap cannot beRepaired\n";
}

