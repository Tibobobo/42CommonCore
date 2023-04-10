#include "Harl.hpp"

int main(int ac, char **av) {

    Harl    test;

    test.complain("DEBUG");
    test.complain("INFO");
    test.complain("LOL");
    test.complain("WARNING");
    test.complain("ERROR");
    return (0);
}