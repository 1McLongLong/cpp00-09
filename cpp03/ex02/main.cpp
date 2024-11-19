#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
  ClapTrap claptrap("ClapMaster");

  claptrap.attack("Toaster");
  claptrap.takeDamage(3);
  claptrap.beRepaired(5);
  claptrap.attack("Blender");
  claptrap.takeDamage(12);
  claptrap.attack("Microwave");

  std::cout << '\n';

  ScavTrap scavtrap("ScavengerBot");

  scavtrap.attack("Toaster Pro");
  scavtrap.takeDamage(30);
  scavtrap.beRepaired(10);
  scavtrap.attack("Blender Deluxe");
  scavtrap.takeDamage(50);
  scavtrap.attack("Microwave Supreme");
  scavtrap.guardGate();

  std::cout << '\n';

  FragTrap fragtrap("Fraginator");

  fragtrap.attack("OvenBot");
  fragtrap.takeDamage(20);
  fragtrap.beRepaired(15);
  fragtrap.attack("DishwasherX");
  fragtrap.takeDamage(40);
  fragtrap.attack("RefrigeratorX");
  fragtrap.highFivesGuys();
  std::cout << '\n';

  return 0;
}

