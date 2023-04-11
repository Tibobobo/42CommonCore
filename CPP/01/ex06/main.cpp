#include "Harl.hpp"

int main(int ac, char **av) {

    Harl    test;

    if (ac != 2)
    {
        std::cout << "[ Probably complaining about insignificant problems ]\n\n";
        return (0);
    }
    std::string level = (std::string)av[1];
    int int_lvl = 0;
    if (level.compare("DEBUG") == 0)
        int_lvl = 1;
    else if (level.compare("INFO") == 0)
        int_lvl = 2;
    else if (level.compare("WARNING") == 0)
        int_lvl = 3;
    else if (level.compare("ERROR") == 0)
        int_lvl = 4;
    switch (int_lvl)
    {
        case 1:
            test.complain("DEBUG");
        case 2:
            test.complain("INFO");
        case 3:
            test.complain("WARNING");
        case 4:
            test.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n\n";
    }
    return (0);
}