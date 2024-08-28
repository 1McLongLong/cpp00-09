#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
  ClapTrap claptrap("Trap_Clap");

  claptrap.attack("Zyamli");
  claptrap.takeDamage(3);
  claptrap.beRepaired(5);
  claptrap.attack("Mmouhiid");
  claptrap.takeDamage(12);
  claptrap.attack("Moichou");

  std::cout << "\n";


  ScavTrap scavtrap("Trap_Scav");

  scavtrap.takeDamage(30);
  scavtrap.beRepaired(10);
  scavtrap.attack("Mohilali");
  scavtrap.takeDamage(50);
  scavtrap.attack("Iassil");
  scavtrap.guardGate();

  std::cout << std::endl;

  return 0;
}

