#include "RobotomyRequestForm.hpp"

class Bureaucrat;

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Request", 72, 45) {

	std::cout << "Default Robotomy Request Form created" << std::endl;
	this->_target = "Default_target";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45) {

	std::cout << "Robotomy Request Form created with target " << target << std::endl;
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm("Robotomy Request", 72, 45) {

	std::cout << "Robotomy Request Form copied"<< std::endl;
	this->_target = src.getTarget();
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {

	this->_target = rhs.getTarget();
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {

	std::cout << "Concrete robotomy request form instance destroyed" << std::endl;
}

int	RobotomyRequestForm::execute(Bureaucrat const &executor) const {

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
	srand(time(NULL) - this->_target.length());
	int	random = rand();
	if (random % 2 == 0)
		std::cout << "* CRRRRRRRRRRRRRRRRRRRRR * " << this->getTarget() << " was successfully robotomised " << std::endl;
	else
		std::cout << "* CRRZBRFFJJJJJ... * Oops, " << this->getTarget() << "'s robotomy seemed to have failed...Oh well..." << std::endl;
	return (0);
}

std::string RobotomyRequestForm::getTarget(void) const {

	return (this->_target);
}