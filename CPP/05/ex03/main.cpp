#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) {

    AForm *form = NULL;

    Intern corenting;
    Bureaucrat fabieng("Fabieng", 3);

    form = corenting.makeForm("robotomy request", "Fabieng");

    fabieng.signForm(*form);
    fabieng.executeForm(*form);
    delete form;

    form = corenting.makeForm("lettre de demission", "Corenting");
    return (0);
}