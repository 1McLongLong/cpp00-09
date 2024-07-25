#include <iostream>
#include "Weapon.hpp"

class HumanA
{
  Weapon m_weapon;
  std::string m_name;
  
  public:
  HumanA(std::string name, Weapon &weapon);
  void attack( void );
};
