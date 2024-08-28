#ifndef FLAGTRAP_H
#define FLAGTRAP_H

#include "ScavTrap.hpp"


class FragTrap : public ClapTrap {
public:
  FragTrap();
  FragTrap(std::string name);
  FragTrap(const FragTrap &copy);
  FragTrap &operator=(const FragTrap &copy);
  ~FragTrap();
  void highFiveGuys(void);
  void attack(const std::string& target);
};



#endif
