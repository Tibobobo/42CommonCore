#include "Dog.hpp"

Dog::Dog(void) {

    _type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
    _brain = new Brain;
}

Dog::Dog(Dog const &src) {

    this->_brain = new Brain(*src.getBrain());
    this->_type = src.getType();
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void) {

    delete _brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog  &Dog::operator=(Dog const &rhs) {

    if (this != &rhs)
    {
        this->_type = rhs.getType();
        delete this->_brain;
        this->_brain = new Brain(*rhs.getBrain());
    }
    return (*this);
}

void    Dog::makeSound(void) const {

    std::cout << "WOOF" << std::endl;
}

Brain   *Dog::getBrain(void) const {

    return (this->_brain);
}