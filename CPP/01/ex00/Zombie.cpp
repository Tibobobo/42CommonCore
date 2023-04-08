#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {

    return ;
}

Zombie::~Zombie(void) {

    std::cout << "Zombie " << this->_name << " died... again ?" << std::endl;
    return ;
}

void    Zombie::announce(void) const {

    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}