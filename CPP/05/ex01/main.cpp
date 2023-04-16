#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {

    Bureaucrat  manu("Macron", 6);
    Bureaucrat  cgt("La CGT", 50);

    Form    ref("Réforme des retraites", 5, 2);
    Form    abrogation("Abrogation de la réforme des retraites", 1, 1);

    std::cout << ref << std::endl;
    try {
        manu.signForm(ref);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << ref << std::endl;
    try {
        manu.upgrade();
        manu.signForm(ref);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << ref << std::endl;
    manu.signForm(ref);
    std::cout <<std::endl << "------A few moments later------" << std::endl << std::endl;
    std::cout << abrogation << std::endl;
    try {
        cgt.signForm(abrogation);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        for (int i = 0; i < 49; i++)
            cgt.upgrade();
        cgt.signForm(abrogation);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << abrogation << std::endl;
    return (0);
}