#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {
	{
		std::cout << "ClapTrap tests" << std::endl << std::endl;

		ClapTrap def;
		ClapTrap didier("Didier");
		ClapTrap steph("Stephanie");
		ClapTrap didier2(didier);
	
		def.beRepaired(10);
		steph.takeDamage(5);
		didier2.takeDamage(50);
		didier2.takeDamage(1);
		didier2.beRepaired(10000);
		didier2.attack("the other Didier");
		for (int i = 0; i < 12; i++)
			def.attack("a tree");
		def.beRepaired(1);
		didier.beRepaired(0);
	}
		std::cout << "_____________________________________________________" << std::endl;
		std::cout << "_____________________________________________________" << std::endl << std::endl;
	{
		std::cout << "ScavTrap tests" << std::endl << std::endl;
		ScavTrap scavDef;
		ScavTrap shigeru("Shigeru");
		ScavTrap wissam("Wissam");
		ScavTrap shigeru2(shigeru);

		scavDef.attack("someone randomly");
		scavDef.takeDamage(56);
		scavDef.beRepaired(30);
		scavDef = wissam;
		scavDef.beRepaired(1);
		wissam.guardGate();
		shigeru.takeDamage(150);
		shigeru.guardGate();
		wissam.guardGate();
		for (int i; i < 52; i++)
			shigeru2.beRepaired(1);
	}
		std::cout << "_____________________________________________________" << std::endl;
		std::cout << "_____________________________________________________" << std::endl << std::endl;
	{
		std::cout << "FragTrap tests" << std::endl << std::endl;
		FragTrap fragDef;
		FragTrap francois("Francois");
		FragTrap houria("Houria");
		FragTrap fragDef2(fragDef);

		fragDef2.attack("himself");
		fragDef2.takeDamage(30);
		fragDef2 = fragDef;
		fragDef2.beRepaired(5);
		houria.highFivesGuys();
		francois.attack("Houria");
		francois.takeDamage(100);
		francois.highFivesGuys();
		francois.beRepaired(10000000);
	}
}