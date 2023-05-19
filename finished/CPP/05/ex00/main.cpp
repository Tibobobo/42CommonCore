#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

int main(void) {

    Bureaucrat def;
    Bureaucrat manu("Macron", 2);

    try {
        def.downgrade();
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << def << std::endl;

    try {
        def.upgrade();
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << def << std::endl;

    std::cout << manu << std::endl;

    try {
        manu.upgrade();
    }
    catch (Bureaucrat::GradeTooHighException &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << manu << std::endl;

    try {
        manu.upgrade();
    }
    catch (Bureaucrat::GradeTooHighException &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << manu << std::endl;

    def = manu;

    std::cout << def << std::endl;

    std::cout << "_________________________________________________\n";
    std::cout << "_________________________________________________\n\n";

    Bureaucrat *copy = NULL;

    try {
        copy = new Bureaucrat(manu);
    }
    catch (std::bad_alloc &ba) {
        std::cerr << "bad_alloc exception caught, exiting program now" << std::endl;
        exit (1);
    }

    std::cout << *copy << std::endl;

    try {
        for (int i = 0; i < 149; i++)
        {
            copy->downgrade();
        }
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << *copy << std::endl;

    try {
        copy->downgrade();
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << *copy << std::endl;

    delete copy;
    return (0);
}