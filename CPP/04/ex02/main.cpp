#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {

    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    delete j;
    delete i;

    std::cout << "_______________________________________________________" << std::endl;
    std::cout << "_______________________________________________________" << std::endl;

    AAnimal	*animals[4];

	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << "New " << animals[i]->getType() << " created at index " << i << std::endl;
	}
	for (int i = 0; i < 4; i++)
		delete animals[i];

    std::cout << "_______________________________________________________" << std::endl;
    std::cout << "_______________________________________________________" << std::endl;

    Brain *brain;
    Dog *toto = new Dog();
    brain = toto->getBrain();
    brain->setIdea(0, "Wesh j'ai faim");
    brain->setIdea(1, "BABALLE");
    std::cout << "Original animal ideas : " << brain->getIdea(0) << ", " << brain->getIdea(1) << std::endl;
    Dog *titi = new Dog(*toto);
    std::cout << "Brain addresses: " << titi->getBrain() << "  " << toto->getBrain() << std::endl;
    std::cout << "Copied animal ideas : " << titi->getBrain()->getIdea(0) << ", " << titi->getBrain()->getIdea(1) << std::endl;
    delete toto;
    delete titi;

    std::cout << "_______________________________________________________" << std::endl;
    std::cout << "_______________________________________________________" << std::endl;

    std::cout << "AAnimal can still be used as base class to build cats and dogs, " << std::endl;
    std::cout << "used as pointer to manipulate cats and dogs, but it cannot be instanced since it now is an abstract class. " << std::endl;
    std::cout << "You can uncomment the last lines of main to see for yourself =)" << std::endl;
    // AAnimal test;
    // AAnimal *pTest = new AAnimal;
}