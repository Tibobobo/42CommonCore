#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &w) : _name(name), _w(w) {

    return ;
}

HumanA::~HumanA(void) {

    return ;
}

void    HumanA::attack(void) const {

    std::cout << this->_name << " attacks with their " << this->_w.getType() << std::endl;
}