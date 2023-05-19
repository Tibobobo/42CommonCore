#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("AAnimal") {

    std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &src) {

    *this = src;
    std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal::~AAnimal(void) {

    std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal  &AAnimal::operator=(AAnimal const &rhs) {

    if (this != &rhs)
        this->_type = rhs.getType();
    return (*this);
}

std::string AAnimal::getType(void) const {

    return (this->_type);
}