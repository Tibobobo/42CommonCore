#include "PresidentialPardonForm.hpp"

class Bureaucrat;

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential Pardon", 25, 5) {

	std::cout << "Default Presidential Pardon Form created" << std::endl;
	this->_target = "Default_target";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 25, 5) {

	std::cout << "Presidential Pardon Form created with target " << target << std::endl;
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm("Presidential Pardon", 25, 5) {

	std::cout << "Presidential Pardon Form copied"<< std::endl;
	this->_target = src.getTarget();
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {

	this->_target = rhs.getTarget();
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {

	std::cout << "Concrete presidential pardon form instance destroyed" << std::endl;
}

int	PresidentialPardonForm::execute(Bureaucrat const &executor) const {

	try {
		this->AForm::isExecutable(executor);
	}
	catch (AForm::NotSignedException &e) {
		std::cout << e.what() << std::endl;
		return (1);
	}
	catch (AForm::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
		return (2);
	}
	std::cout << this->getTarget() << " was pardoned by Zaphod Beeblebrox" << std::endl;
	return (0);
}

std::string PresidentialPardonForm::getTarget(void) const {

	return (this->_target);
}