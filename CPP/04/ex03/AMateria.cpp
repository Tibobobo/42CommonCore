#include "AMateria.hpp"

#include <iostream>

AMateria::AMateria(void) {

	this->_type = "none";
}

AMateria::AMateria(std::string const &type) {

	this->_type = type;
}

AMateria::AMateria(AMateria const &src) {

	this->_type = src.getType();
}

AMateria::~AMateria(void) {

}

AMateria &AMateria::operator=(AMateria const &rhs) {

	if (this != &rhs)
        this->_type = rhs.getType();
    return (*this);
}

std::string const &AMateria::getType(void) const {

	return (this->_type);
}

void	AMateria::use(ICharacter &target) {

	std::cout << "'* does absolutely nothing to " << target.getName() << " *'" << std::endl;
}