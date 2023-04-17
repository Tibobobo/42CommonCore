#include "ShrubberyCreationForm.hpp"

class Bureaucrat;

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Creation", 145, 137) {

	std::cout << "Default Shrubbery Creation Form created" << std::endl;
	this->_target = "Default_target";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation", 145, 137) {

	std::cout << "Shrubbery Creation Form created with target " << target << std::endl;
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm("Shrubbery Creation", 145, 137) {

	std::cout << "Shrubbery Creation Form copied"<< std::endl;
	this->_target = src.getTarget();
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {

	this->_target = rhs.getTarget();
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {

}

int	ShrubberyCreationForm::execute(Bureaucrat const &executor) const {

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
	std::string filename = this->_target + "_shrubbery";
	std::ofstream file;
	file.open(filename);
	if (file.is_open())
	{
		file << "             ,@@@@@@@,\n"
      << " ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
<< "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
<< "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
<< "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
<< "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
<< "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
<< "       |o|        | |         | |\n"
<< "       |.|        | |         | |\n"
<< "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_";
		file.close();
		return (0);
	}
	else
		std::cout << "Error while creating shrubbery file" << std::endl;
	return (-1);
	
	
}

std::string ShrubberyCreationForm::getTarget(void) const {

	return (this->_target);
}