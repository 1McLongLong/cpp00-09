#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Trap_Clap")
{
  std::cout << "ScavTrap is IN\n";
  this->hit_points = 100;
  this->energy_points = 50;
  this->attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap("Trap_Clap")
{
  std::cout << "ScavTrap is IN\n";
  this->name = name;
  this->hit_points = 100;
  this->energy_points = 50;
  this->attack_damage = 20;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap is OUT\n";
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap is now in GATE KEEPER mode\n";
}


void ScavTrap::attack(const std::string& target)
{
  if (hit_points <= 0 || energy_points <= 0)
    std::cout << "ScavTrap can't attack anymore unfortunately\n";
  else
    std::cout << "ScavTrap " << name << " attacks " 
            << target << ", causing " << attack_damage 
            << " points of damage!\n";
}

void ScavTrap::takeDamage(unsigned int amount)
{
  std::cout << "ScavTrap is edging " << amount << " points out of him\n";
  if (hit_points > 0)
    hit_points -= amount;
  if (energy_points > 0)
    energy_points--;
}

void ScavTrap::beRepaired(unsigned int amount)
{
  hit_points += amount;
  if (energy_points > 0)
    energy_points--;
  std::cout << "ScavTrap's aura is gaining " << amount << " points\n";
}



