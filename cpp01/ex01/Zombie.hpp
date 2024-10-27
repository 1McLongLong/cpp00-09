#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
  std::string m_name;

  public:
  Zombie(std::string name);
  Zombie(void);
  ~Zombie(void);
  void  set_Name(std::string name);
  void  announce( void );
};

Zombie *zombieHorde(int N, std::string name);

#endif
