#include "ClapTrap.hpp"


int main() {
  ClapTrap claptrap("Trap_Clap");

  claptrap.attack("Zyamli");
  claptrap.takeDamage(3);
  claptrap.beRepaired(5);
  claptrap.attack("Mmouhiid");
  claptrap.takeDamage(12);
  claptrap.attack("Moichou");
  return 0;
}
