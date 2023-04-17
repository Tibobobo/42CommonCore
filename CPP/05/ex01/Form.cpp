#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : _name("Default"), _signed(false), _sGrade(150), _eGrade(150) {

    std::cout << "Default Form created" << std::endl;
}

Form::Form(std::string const name, unsigned int const sGrade, unsigned int const eGrade) : _name(name), _signed(false), _sGrade(sGrade), _eGrade(eGrade) {

    if (this->_sGrade < 1 || this->_eGrade < 1)
        throw (Form::GradeTooHighException());
    if (this->_sGrade > 150 || this->_sGrade > 150)
        throw (Form::GradeTooLowException());
    std::cout << this->getName() << " Form created" << std::endl;
}

Form::Form(Form const &src) : _name(src.getName()), _signed(src.getSigned()), _sGrade(src.getSGrade()), _eGrade(src.getEGrade()) {

    std::cout << this->getName() << " Form was copied" << std::endl;
}

Form::~Form(void) {

    std::cout << this->getName() << " Form destroyed" << std::endl;
}

Form &Form::operator=(Form const &rhs) {

    this->_signed = rhs.getSigned();
    // only signed status can be assigned since everything else is const
    return (*this);
}

std::string const Form::getName(void) const {

    return (this->_name);
}

bool Form::getSigned(void) const {

    return (this->_signed);
}

unsigned int const Form::getSGrade(void) const {

    return (this->_sGrade);
}

unsigned int const Form::getEGrade(void) const {

    return (this->_eGrade);
}

bool    Form::beSigned(Bureaucrat &b) {

    if (b.getGrade() > this->_sGrade)
    {
        throw (Bureaucrat::GradeTooLowException());
        return (false);
    }
    this->_signed = 1;
    return (true);
}

const char *Form::GradeTooLowException::what(void) const throw() {

    return ("Form exception: Grade too low");
}

const char *Form::GradeTooHighException::what(void) const throw() {

    return ("Form exception: Grade too high");
}

std::ostream &operator<<(std::ostream &o, Form const &f) {

    o << "Form " << f.getName() << " , sign grade : " << f.getSGrade();
    o << ", execute grade : " << f.getEGrade() << ", is ";
    if (f.getSigned() == false)
        o << "not yet ";
    o << "signed. ";
    return (o);
}