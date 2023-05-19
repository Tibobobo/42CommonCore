#include "Animal.hpp"

Animal::Animal(void) : _type("Animal") {

    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const &src) {

    *this = src;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal(void) {

    std::cout << "Animal destructor called" << std::endl;
}

Animal  &Animal::operator=(Animal const &rhs) {

    if (this != &rhs)
        this->_type = rhs.getType();
    return (*this);
}

std::string Animal::getType(void) const {

    return (this->_type);
}

void    Animal::makeSound(void) const {

    std::cout << "**UNIDENTIFIED ANIMAL SOUND**" << std::endl;
}

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal") {

    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) {

    *this = src;
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {

    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal  &WrongAnimal::operator=(WrongAnimal const &rhs) {

    if (this != &rhs)
        this->_type = rhs.getType();
    return (*this);
}

std::string WrongAnimal::getType(void) const {

    return (this->_type);
}

void    WrongAnimal::makeSound(void) const {

    std::cout << "**UNIDENTIFIED WRONG ANIMAL SOUND**" << std::endl;
}