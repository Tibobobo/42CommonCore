#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    std::cout << "_______________________________________________________" << std::endl;
    std::cout << "_______________________________________________________" << std::endl;

    Animal	*animals[4];
	Brain	*brain;

	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << "New " << animals[i]->getType() << " created at index " << i << std::endl;
	}

	brain = animals[2]->getBrain();
	brain->setIdea(0, "Vasy Flemme");
	brain->setIdea(1, "eh gros ca y est");
	std::cout << "Original animal ideas : " << brain->getIdea(0) << ", " << brain->getIdea(1) << std::endl;

	*(animals[3]) = *(animals[2]);
    std::cout << animals[3]->getBrain() << "  " << animals[2]->getBrain() << std::endl;
    std::cout << "Assigned animal ideas : " << animals[3]->getBrain()->getIdea(0) << ", " << animals[3]->getBrain()->getIdea(1) << std::endl;
	for (int i = 0; i < 4; i++)
		delete animals[i];

    std::cout << "_______________________________________________________" << std::endl;
    std::cout << "_______________________________________________________" << std::endl;

    Dog *toto = new Dog();
    brain = toto->getBrain();
    brain->setIdea(0, "Wesh j'ai faim");
    brain->setIdea(1, "BABALLE");
    std::cout << "Original animal ideas : " << brain->getIdea(0) << ", " << brain->getIdea(1) << std::endl;
    Dog *titi = new Dog(*toto);
    std::cout << "Copied animal ideas : " << titi->getBrain()->getIdea(0) << ", " << titi->getBrain()->getIdea(1) << std::endl;
    delete toto;
}