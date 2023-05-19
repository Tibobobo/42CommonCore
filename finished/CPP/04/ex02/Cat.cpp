#include "Cat.hpp"

Cat::Cat(void) {

    _type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
    _brain = new Brain;
}

Cat::Cat(Cat const &src) {

    this->_brain = new Brain(*src.getBrain());
    this->_type = src.getType();
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void) {

    delete _brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat  &Cat::operator=(Cat const &rhs) {

    if (this != &rhs)
    {
        this->_type = rhs.getType();
        delete this->_brain;
        this->_brain = new Brain(*rhs.getBrain());
    }
    return (*this);
}

void    Cat::makeSound(void) const {

    std::cout << "MEOW" << std::endl;
}

Brain   *Cat::getBrain(void) const {

    return (this->_brain);
}