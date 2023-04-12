#include "ClapTrap.hpp"

int	main(void) {

	ClapTrap def;
	ClapTrap didier("Didier");
	ClapTrap steph("Stephanie");
	ClapTrap didier2(didier);
	
	def.beRepaired(10);
	steph.takeDamage(5);
	didier2.takeDamage(50);
	didier2.beRepaired(10000);
	didier2.attack("the other Didier");
	for (int i = 0; i < 12; i++)
		def.attack("a tree");
	def.beRepaired(1);
	didier.beRepaired(0);
}