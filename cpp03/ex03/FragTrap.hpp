#ifndef FLAGTRAP_H
#define FLAGTRAP_H

#include "ScavTrap.hpp"


class FragTrap : virtual public ClapTrap {
public:
  FragTrap();
  FragTrap(std::string name);
  FragTrap(const FragTrap &copy);
  FragTrap &operator=(const FragTrap &copy);
  ~FragTrap();
  void highFivesGuys(void);
};



#endif
