#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {

	this->_hp = 100;
	this->_ep = 50;
	this->_atk = 20;
	this->_guard = false;

	std::cout << "Default ST constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {

	this->_hp = 100;
	this->_ep = 50;
	this->_atk = 20;
	this->_guard = false;

	std::cout << "ST constructor called with name " << name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) {

	std::cout << "ST copy constructor called, copying from "  << src.getName()  << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(void) {

	std::cout << "ST Destructor called " << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs) {

	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hp = rhs.getHp();
		this->_ep = rhs.getEp();
		this->_atk = rhs.getAtk();
		this->_guard = rhs.getGuard();
	}
	return (*this);
}

void	ScavTrap::attack(const std::string &target) {

	if (this->_hp == 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't attack " << target;
		std::cout << " because it's dead..." << std::endl;
		return ;
	}
	else if (this->_ep <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't attack " << target;
		std::cout << " because it has no EP left..." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target;
	std::cout << ", causing " << this->_atk << " points of damage !" << std::endl;
	this->_ep--;
}

bool	ScavTrap::getGuard(void) const {

	return (this->_guard);
}

void    ScavTrap::guardGate(void) {

	if (this->_hp == 0)
		std::cout << "ScavTrap " << this->_name << " can't guard anything when it's dead..." << std::endl;
	else if (this->_guard == false)
	{
		this->_guard = true;
		std::cout << "ScavTrap " << this->_name << " : Gate Keeper Mode : ACTIVATED" << std::endl; 
	}
	else
	{
		this->_guard = false;
		std::cout << "ScavTrap " << this->_name << " : Gate Keeper Mode : DEACTIVATED" << std::endl; 
	}
}