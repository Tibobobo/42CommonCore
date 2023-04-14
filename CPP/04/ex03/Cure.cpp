#include "Cure.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure") {

}

Cure::Cure(Cure const &src) {

	*this = src;
}

Cure::~Cure(void) {

}

Cure &Cure::operator=(Cure const &rhs) {

    return (*this);
}

std::string const &Cure::getType(void) const {

	return (this->_type);
}

Cure* Cure::clone(void) const {

	Cure *res = new Cure;
	return (res);
}

void	Cure::use(ICharacter &target) {

	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}