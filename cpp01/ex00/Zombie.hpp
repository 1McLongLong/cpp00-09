#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
  std::string m_name;

  public:
  void  announce(void);
  Zombie(std::string name);
  ~Zombie(void);
};

Zombie *newZombie(std::string name);
void    randomChump(std::string name);

#endif
