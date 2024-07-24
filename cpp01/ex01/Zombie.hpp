#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
  std::string m_name;

  public:
  void  announce( void );
  Zombie(std::string name);
  Zombie(void);
  ~Zombie(void);
  void set_Name(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif
