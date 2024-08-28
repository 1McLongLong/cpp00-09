#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("") {
  std::cout << "FragTrap default constructor is IN\n";
  this->hit_points = 100;
  this->energy_points = 100;
  this->attack_damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  std::cout << "FragTrap is IN\n";
  this->name = name;
  this->hit_points = 100;
  this->energy_points = 100;
  this->attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
  std::cout << "Copy constructor called\n";
  *this = copy;
}

FragTrap &FragTrap::operator=(const FragTrap &copy) {
  std::cout << "FragTrap Assignment operator called\n";
  if (this != &copy) {
    ClapTrap::operator=(copy);
  }
  return *this;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap is OUT\n";
}

void FragTrap::highFiveGuys(void) {
  std::cout << "HI HI HI GIMME A HIGH FIVE GUYS\n";
}


void FragTrap::attack(const std::string& target) {
  if (hit_points <= 0 || energy_points <= 0)
    std::cout << "FragTrap can't attack anymore unfortunately\n";
  else
    std::cout << "FragTrap " << name << " attacks " 
            << target << ", causing " << attack_damage 
            << " points of damage!\n";
}




