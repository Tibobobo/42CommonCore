#include "Zombie.hpp"

int main(void) {

    Zombie  *test;

    std::cout << "Generating a horde of 10 zombies" << std::endl << std::endl;
    test = zombieHorde(10, "Didier");
    for (int i = 0 ; i < 10 ; i++)
        test[i].announce();
    delete [] test;

    std::cout << std::endl << "Generating a horde of 100 zombies" << std::endl << std::endl;
    test = zombieHorde(100, "Stephanie");
    for (int i = 0 ; i < 100 ; i++)
        test[i].announce();
    delete [] test;

    std::cout << std::endl << "Generating a horde of...1 zombie" << std::endl << std::endl;
    test = zombieHorde(1, "Rodrigo");
    for (int i = 0 ; i < 1 ; i++)
        test[i].announce();
    delete [] test;

    std::cout << std::endl << "End" << std::endl;
    return (0);
}