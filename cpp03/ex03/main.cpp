#include "DiamondTrap.hpp"

int	main(void)
{
	FragTrap	bob = FragTrap("Bob");

	bob.attack("a worm");
	bob.takeDamage(9);

	DiamondTrap	bib = DiamondTrap("Bib");

	bib.whoAmI();
	bib.attack("a human");
	bib.highFivesGuys();
	bib.beRepaired(5);
}

