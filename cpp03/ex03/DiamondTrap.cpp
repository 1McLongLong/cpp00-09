#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : name("default") {
  std::cout << "FragTrap default constructor is IN\n";
  this->hit_points = 100;
  this->energy_points = 50;
  this->attack_damage = 30;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name") {
  std::cout << "FragTrap is IN\n";
  this->name = name;
  this->hit_points = 100;
  this->energy_points = 50;
  this->attack_damage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy), name(copy.name) {
  std::cout << "Copy constructor called\n";
  *this = copy;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy) {
  std::cout << "FragTrap Assignment operator called\n";
  if (this != &copy) {
    ClapTrap::operator=(copy);
    this->name = copy.name;
    this->hit_points = copy.hit_points;
    this->energy_points = copy.energy_points;
    this->attack_damage = copy.attack_damage;
  }
  return *this;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "FragTrap is OUT\n";
}

void DiamondTrap::whoAmI() {
  std::cout << "I am " << this->name << ", and my ClapTrap name is " << ClapTrap::name << std::endl;
}

