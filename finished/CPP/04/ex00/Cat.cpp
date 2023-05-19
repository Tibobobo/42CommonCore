#include "Cat.hpp"

Cat::Cat(void) {

    _type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const &src) {

    *this = src;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void) {

    std::cout << "Cat destructor called" << std::endl;
}

Cat  &Cat::operator=(Cat const &rhs) {

    if (this != &rhs)
        this->_type = rhs.getType();
    return (*this);
}

void    Cat::makeSound(void) const {

    std::cout << "MEOW" << std::endl;
}

WrongCat::WrongCat(void) {

    _type = "WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src) {

    *this = src;
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat(void) {

    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat  &WrongCat::operator=(WrongCat const &rhs) {

    if (this != &rhs)
        this->_type = rhs.getType();
    return (*this);
}

void    WrongCat::makeSound(void) const {

    std::cout << "Wrong MEOW" << std::endl;
}