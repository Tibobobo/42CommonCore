#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : _name("Default"), _signed(false), _sGrade(150), _eGrade(150) {

    std::cout << "Default AForm created" << std::endl;
}

AForm::AForm(std::string const name, unsigned int const sGrade, unsigned int const eGrade) : _name(name), _signed(false), _sGrade(sGrade), _eGrade(eGrade) {

    if (this->_sGrade < 1 || this->_eGrade < 1)
        throw (AForm::GradeTooHighException());
    if (this->_sGrade > 150 || this->_sGrade > 150)
        throw (AForm::GradeTooLowException());
    std::cout << this->getName() << " AForm created" << std::endl;
}

AForm::AForm(AForm const &src) : _name(src.getName()), _signed(src.getSigned()), _sGrade(src.getSGrade()), _eGrade(src.getEGrade()) {

    std::cout << this->getName() << " AForm was copied" << std::endl;
}

AForm::~AForm(void) {

    std::cout << this->getName() << " AForm destroyed" << std::endl;
}

AForm &AForm::operator=(AForm const &rhs) {

    this->_signed = rhs.getSigned();
    // only signed status can be assigned since everything else is const
    return (*this);
}

std::string const AForm::getName(void) const {

    return (this->_name);
}

bool AForm::getSigned(void) const {

    return (this->_signed);
}

unsigned int const AForm::getSGrade(void) const {

    return (this->_sGrade);
}

unsigned int const AForm::getEGrade(void) const {

    return (this->_eGrade);
}

bool    AForm::beSigned(Bureaucrat &b) {

    if (b.getGrade() > this->_sGrade)
    {
        throw (Bureaucrat::GradeTooLowException());
        return (false);
    }
    this->_signed = 1;
    return (true);
}

bool    AForm::isExecutable(Bureaucrat const &b) const {

    if (this->getSigned() == false)
    {
        throw (AForm::NotSignedException());
        return (false);
    }
    else if (this->getEGrade() < b.getGrade())
    {
        throw (AForm::GradeTooHighException());
        return (false);
    }
    return (true);
}

const char *AForm::GradeTooLowException::what(void) const throw() {

    return ("AForm exception: Grade too low");
}

const char *AForm::GradeTooHighException::what(void) const throw() {

    return ("AForm exception: Grade too high");
}

const char *AForm::NotSignedException::what(void) const throw() {

    return ("AForm exception: This Form isn't signed");
}

std::ostream &operator<<(std::ostream &o, AForm const &f) {

    o << "AForm " << f.getName() << " , sign grade : " << f.getSGrade();
    o << ", execute grade : " << f.getEGrade() << ", is ";
    if (f.getSigned() == false)
        o << "not yet ";
    o << "signed. ";
    return (o);
}