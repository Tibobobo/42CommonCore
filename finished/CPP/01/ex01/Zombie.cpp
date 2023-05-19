#include "Zombie.hpp"

Zombie::Zombie(void) {

    return ;
}

Zombie::~Zombie(void) {

    std::cout << "Zombie " << this->_name << " died... again ?" << std::endl;
    return ;
}

void    Zombie::announce(void) const {

    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string name) {

    this->_name = name;
}