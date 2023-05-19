#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("Default_clap_name") {

    this->_name = "Default";
	this->_hp = FragTrap::_hp;
	this->_ep = ScavTrap::_ep;
	this->_atk = FragTrap::_atk;

	std::cout << "Default DT constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") {

    this->_name = name;
	this->_hp = FragTrap::_hp;
	this->_ep = ScavTrap::_ep;
	this->_atk = FragTrap::_atk;

	std::cout << "DT constructor called with name " << name << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src), ScavTrap(src), FragTrap(src) {

	std::cout << "DT copy constructor called, copying from "  << src.getName()  << std::endl;
	*this = src;
}

DiamondTrap::~DiamondTrap(void) {

	std::cout << "DT Destructor called " << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &rhs) {

	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hp = rhs.getHp();
		this->_ep = rhs.getEp();
		this->_atk = rhs.getAtk();
		ClapTrap::_name = rhs.getName() + "_clap_name";
	}
	return (*this);
}

void	DiamondTrap::attack(const std::string &target) {

    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI(void) {

	if (this->_hp == 0)
		std::cout << "FragTrap " << this->_name << " would introduce itself if it weren't dead..." << std::endl;
	else
		std::cout << this->_name << " : Hi, I'm a DiamondTrap. My name is " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << " !" << std::endl;
}

std::string DiamondTrap::getName(void) const {

	return (this->_name);
}