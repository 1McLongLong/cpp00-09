#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("default") {
  std::cout << "ScavTrap default constructor is IN\n";
  this->hit_points = 100;
  this->energy_points = 50;
  this->attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  std::cout << "ScavTrap is IN\n";
  this->name = name;
  this->hit_points = 100;
  this->energy_points = 50;
  this->attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
  std::cout << "Copy constructor called\n";
  *this = copy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy) {
  std::cout << "ScavTrap Assignment operator called\n";
  if (this != &copy) {
    ClapTrap::operator=(copy);
  }
  return *this;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap is OUT\n";
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap is now in GATE KEEPER mode\n";
}


void ScavTrap::attack(const std::string& target) {
  if (hit_points <= 0 || energy_points <= 0)
    std::cout << "ScavTrap can't attack anymore unfortunately\n";
  else
    std::cout << "ScavTrap " << name << " attacks " 
            << target << ", causing " << attack_damage 
            << " points of damage!\n";
}

