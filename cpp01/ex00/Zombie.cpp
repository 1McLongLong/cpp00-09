#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
  this->m_name = name;
  std::cout << m_name << " object Createeeeeeeeeed\n";
}

Zombie::~Zombie(void) {
  std::cout << m_name << " Destrooooooooyed\n";
}

void Zombie::announce( void ) {
  std::cout << m_name << ": BraiiiiiiinnnzzzZ...\n";
}

