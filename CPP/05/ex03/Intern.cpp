#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void) {

    std::cout << "A new Intern was born" << std::endl;
}

Intern::Intern(Intern const &src) {

    *this = src;
}

Intern::~Intern(void) {

    std::cout << "An intern was thanked, after having been paid in visibility" << std::endl;
}

Intern &Intern::operator=(Intern const &rhs) {

    (void)rhs;
    return (*this);
}

AForm	*makePardonForm(const std::string target) {

	return (new PresidentialPardonForm(target));
}

AForm	*makeRobotomyForm(const std::string target) {

	return (new RobotomyRequestForm(target));
}

AForm	*makeShrubberyForm(const std::string target) {

	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(std::string const type, std::string const formTarget) const {

	AForm *(*funPtrArray[])(const std::string target) = {&makePardonForm, &makeRobotomyForm, &makeShrubberyForm};
	std::string forms[] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	for (int i = 0; i < 3; i++)
	{
		if (type == forms[i])
		{
			std::cout << "Intern created a " << type << " form" << std::endl;
			return (funPtrArray[i](formTarget));
		}
	}

	std::cout << "Intern can't create a form called " << type  << std::endl;
	return (NULL);
}