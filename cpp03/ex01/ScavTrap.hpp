#ifndef SCAVTRAP_H
#define SCAVTRAP_H



#include "ClapTrap.hpp"


class ScavTrap : public ClapTrap {
public:
  ScavTrap();
  ScavTrap(std::string name);
  ~ScavTrap();
  void guardGate();
  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};




#endif
