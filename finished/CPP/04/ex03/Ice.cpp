# include "Ice.hpp"
# include <iostream>

Ice::Ice(void) : AMateria("ice") {

}

Ice::Ice(Ice const &src) : AMateria(src) {

}

Ice::~Ice(void) {

}

Ice &Ice::operator=(Ice const &rhs) {

    return (*this);
}

std::string const &Ice::getType(void) const {

	return (this->_type);
}

Ice* Ice::clone(void) const {

	Ice *res = new Ice;
	return (res);
}

void	Ice::use(ICharacter &target) {

	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}