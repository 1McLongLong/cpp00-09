#ifndef SCAVTRAP_H
#define SCAVTRAP_H



#include "ClapTrap.hpp"


class ScavTrap : virtual public ClapTrap {
public:
  ScavTrap();
  ScavTrap(std::string name);
  ScavTrap &operator=(const ScavTrap& copy);
  ScavTrap(const ScavTrap &copy);
  ~ScavTrap();
  void guardGate();
  void attack(const std::string& target);
};




#endif
