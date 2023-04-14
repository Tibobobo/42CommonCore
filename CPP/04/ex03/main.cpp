# include "MateriaSource.hpp"
# include "Character.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

int	main(void) {

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;

	std::cout << "_________________________________________________________" << std::endl;
	std::cout << "_________________________________________________________" << std::endl;
	Character cloud("Cloud");
	Character tifa("Tifa");

	cloud.equip(src->createMateria("ice"));
	cloud.equip(src->createMateria("meteor"));
	cloud.equip(src->createMateria("cure"));

	cloud.use(0, tifa);
	cloud.use(1, tifa);
	std::cout << "cure is stored in slot 1 because meteor wasn't found\n" << std::endl;
	cloud.use(2, tifa);

	AMateria const *tmp2 = cloud.getMateria(0);  //save address before unequipping to avoid leaks
	cloud.unequip(0);

	cloud.unequip(3); //does nothing because slot 3 is empty

	for (int i = 0; i < 3; i++)
		cloud.equip(src->createMateria("ice")); // adding 3 ice materias to empty slots
	for (int i = 0; i < 4; i++)
		cloud.use(i, tifa);						//use all 4 materias

	AMateria *tmp3 = src->createMateria("cure");
	cloud.equip(tmp3);							//does nothing because inventory is full

	cloud = tifa;

	std::cout << "Cloud's name is now " << cloud.getName() << std::endl;
	cloud.equip(tmp3);						// this time inventory is empty since cloud was re-assigned to tifa
	cloud.use(0, tifa);
	cloud.unequip(0);					

	delete tmp3;
	delete tmp2;
	delete src;
	return 0;
}