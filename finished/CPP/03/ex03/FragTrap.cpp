#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {

	this->_hp = 100;
	this->_ep = 100;
	this->_atk = 30;

	std::cout << "Default FT constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {

	this->_hp = 100;
	this->_ep = 100;
	this->_atk = 30;

	std::cout << "FT constructor called with name " << name << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) {

	std::cout << "FT copy constructor called, copying from "  << src.getName()  << std::endl;
	*this = src;
}

FragTrap::~FragTrap(void) {

	std::cout << "FT Destructor called " << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &rhs) {

	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hp = rhs.getHp();
		this->_ep = rhs.getEp();
		this->_atk = rhs.getAtk();
	}
	return (*this);
}

void	FragTrap::attack(const std::string &target) {

	if (this->_hp == 0)
	{
		std::cout << "FragTrap " << this->_name << " can't attack " << target;
		std::cout << " because it's dead..." << std::endl;
		return ;
	}
	else if (this->_ep <= 0)
	{
		std::cout << "FragTrap " << this->_name << " can't attack " << target;
		std::cout << " because it has no EP left..." << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " attacks " << target;
	std::cout << ", causing " << this->_atk << " points of damage !" << std::endl;
	this->_ep--;
}

void    FragTrap::highFivesGuys(void) {

	if (this->_hp == 0)
		std::cout << "FragTrap " << this->_name << " would ask for high fives if it weren't dead..." << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " happily offers high fives to anyone interested !" << std::endl; 
}