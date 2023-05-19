#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void) {
	
	DiamondTrap	def;
	DiamondTrap toto("Toto");

	def.whoAmI();
	toto.whoAmI();
	toto.attack("everyone around it");
	toto.takeDamage(50);
	toto.beRepaired(20);
	toto.guardGate();
	toto.guardGate();
	toto.highFivesGuys();
	toto = def;
	toto.whoAmI();
	def.whoAmI();
}