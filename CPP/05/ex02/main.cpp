#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {

    Bureaucrat b150("B150", 150);
    Bureaucrat b140("B140", 140);
    Bureaucrat b100("B100", 100);
    Bureaucrat b50("B50", 50);
    Bureaucrat b20("B20", 20);
    Bureaucrat b6("B6", 6);

    AForm *shr = new ShrubberyCreationForm("test");
    AForm *rob = new RobotomyRequestForm("Zaphod Beeblebrox");
    AForm *pres = new PresidentialPardonForm("I");

    std::cout << shr->getSigned() << "  " << shr->getEGrade() << "   " << shr->getSGrade() << std::endl;

    std::cout << std::endl << "__________________________________________________" << std::endl;
    std::cout << "__________________________________________________" << std::endl << std::endl;
    std::cout << "----------Shrubbery Test----------" << std::endl;
    try {
        b150.signForm(*shr);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        b140.signForm(*shr);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        b100.signForm(*shr);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        b140.executeForm(*shr);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        b100.executeForm(*shr);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        b100.executeForm(*shr);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << "__________________________________________________" << std::endl;
    std::cout << "__________________________________________________" << std::endl << std::endl;
    std::cout << "----------Robotomy Test----------" << std::endl;
    try {
        b100.signForm(*rob);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        b50.signForm(*rob);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        b50.executeForm(*rob);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        b20.executeForm(*rob);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        b20.executeForm(*rob);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        b20.executeForm(*rob);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl << "__________________________________________________" << std::endl;
    std::cout << "__________________________________________________" << std::endl << std::endl;
    std::cout << "----------Presidential Pardon Test----------" << std::endl;
    try {
        b20.signForm(*pres);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        b6.executeForm(*rob);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    b6.upgrade();
    try {
        b6.executeForm(*rob);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    delete shr;
    delete rob;
    delete pres;
    return (0);
}