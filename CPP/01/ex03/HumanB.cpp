#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {

    this->_w = NULL;
    return ;
}

HumanB::~HumanB(void) {

    return ;
}

void    HumanB::attack(void) const {

    if (this->_w != NULL)
        std::cout << this->_name << " attacks with their " << this->_w->getType() << std::endl;
    else
        std::cout << this->_name << " has no weapon, so decides to sing a little song" << std::endl;
}

void    HumanB::setWeapon(Weapon &w) {

    this->_w = &w;
}