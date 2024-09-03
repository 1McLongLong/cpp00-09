#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H


#include "FragTrap.hpp"


class DiamondTrap : public ScavTrap, public FragTrap {
  std::string name;
  public:
  DiamondTrap();
  DiamondTrap(std::string name);
  DiamondTrap(const DiamondTrap &copy);
  DiamondTrap &operator=(const DiamondTrap &copy);
  ~DiamondTrap();
  void whoAmI();
};





#endif
