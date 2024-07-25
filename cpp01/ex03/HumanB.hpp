#include <iostream>
#include "Weapon.hpp"

class HumanB
{
  Weapon m_weapon;
  std::string m_name;
  
  public:
  HumanB(std::string);
  void attack( void );
  void setWeapon(Weapon &weapon);
};
