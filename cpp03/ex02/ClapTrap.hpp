#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>


class ClapTrap {
protected:
  std::string name;
  int         hit_points;
  int         energy_points;
  int         attack_damage;

public:
  ClapTrap();
  ClapTrap(std::string name);
  ClapTrap(const ClapTrap &copy);
  ClapTrap &operator=(const ClapTrap &copy);
  ~ClapTrap();
  void        attack(const std::string& target);
  void        takeDamage(unsigned int amount);
  void        beRepaired(unsigned int amount);
};



#endif
