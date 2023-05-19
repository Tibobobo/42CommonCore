#include "Brain.hpp"

Brain::Brain(void)  {

    for (int i = 0; i < 100; i++)
        this->_ideas[i] = "...";
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const &src) {

    for (int i = 0; i < 100; i++)
            this->_ideas[i] = src.getIdea(i);
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain(void) {

    std::cout << "Brain destructor called" << std::endl;
}

Brain  &Brain::operator=(Brain const &rhs) {

    if (this != &rhs)
    {
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = rhs.getIdea(i);
    } 
    return (*this);
}

std::string Brain::getIdea(int i) const {

    if (i < 0 || i > 99)
        return (NULL);
    return (this->_ideas[i]);
}

void Brain::setIdea(int i, std::string idea) {

    if (i < 0 || i > 99)
        return ;
    this->_ideas[i] = idea;
}