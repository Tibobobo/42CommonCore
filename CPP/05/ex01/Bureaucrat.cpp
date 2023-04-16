#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void) : _grade(150), _name("Default") {

    std::cout << "Bureaucrat " << this->getName() << ", grade " << this->getGrade() << " was born" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, unsigned int grade) : _name(name) {

    this->setGrade(grade);
    std::cout << "Bureaucrat " << this->getName() << ", grade " << this->getGrade() << " was born" << std::endl;

}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src.getName()) {

    this->setGrade(src.getGrade());
    std::cout << "Bureaucrat " << this->getName() << ", grade " << this->getGrade() << " was cloned" << std::endl;

}

Bureaucrat::~Bureaucrat(void) {

    std::cout << this->getName() << " explosion !!!" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {

    if (this != &rhs)
        this->setGrade(rhs.getGrade());
    return (*this);
}

std::string const Bureaucrat::getName(void) const {

    return (this->_name);
}

unsigned int Bureaucrat::getGrade(void) const {

    return (this->_grade);
}

void    Bureaucrat::setGrade(unsigned int grade) {

    if (grade < 1)
        throw (Bureaucrat::GradeTooHighException());
    else if (grade > 150)
        throw (Bureaucrat::GradeTooLowException());
    else
        this->_grade = grade;
}

void    Bureaucrat::upgrade(void) {

    this->setGrade(this->_grade - 1);
}

void    Bureaucrat::downgrade(void) {

    this->setGrade(this->_grade + 1);
}

bool    Bureaucrat::signForm(Form &f) const {

    if (f.getSigned() == true)
    {
        std::cout << "Bureaucrat " << this->_name << " couldn't sign " << f.getName() << "because it's already signed" << std::endl;
        return (false);
    }
    else if (f.beSigned(*this) == true)
    {
        std::cout << "Bureaucrat " << this->_name << " signed " << f.getName() << std::endl;
        return (true);
    }
    std::cout << "Bureaucrat " << this->_name << "couldn't sign " << f.getName() << " because their grade is too low" << std::endl;
    return (false);
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw() {

    return ("Bureaucrat exception: Grade too low");
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw() {

    return ("Bureaucrat exception: Grade too high");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &b) {

    o << b.getName() << ", bureaucrat grade " << b.getGrade();
    return (o);
}