#include "Zombie.hpp"

int main(int ac, char **av) {

    Zombie  *test;

    if (ac != 3)
    {
        std::cout << "Please launch program with 2 arguments corresponding to the names of the two Zombies it will create" << std::endl;
        return (1);
    }
    randomChump(av[1]);
    test = newZombie(av[2]);
    test->announce();
    delete test;
    return (0);
}