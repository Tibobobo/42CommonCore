#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default"), _hp(10), _ep(10), _atk(0) {

	std::cout << "Default CT constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _atk(0) {

	std::cout << "CT constructor called with name " << name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) {

	std::cout << "CT copy constructor called, copying from "  << src.getName()  << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void) {

	std::cout << "CT Destructor called " << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs) {

	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hp = rhs.getHp();
		this->_ep = rhs.getEp();
		this->_atk = rhs.getAtk();
	}
	return (*this);
}

std::string	ClapTrap::getName(void) const {

	return (this->_name);
}

int	ClapTrap::getHp(void) const {

	return (this->_hp);
}

int	ClapTrap::getEp(void) const {

	return (this->_ep);
}

int	ClapTrap::getAtk(void) const {

	return (this->_atk);
}

void	ClapTrap::attack(const std::string &target) {

	if (this->_hp == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't attack " << target;
		std::cout << " because it's dead..." << std::endl;
		return ;
	}
	else if (this->_ep <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't attack " << target;
		std::cout << " because it has no EP left..." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target;
	std::cout << ", causing " << this->_atk << " points of damage !" << std::endl;
	this->_ep--;
}

void	ClapTrap::takeDamage(unsigned int amount) {

	if (this->_hp == 0)
	{
		std::cout << this->_name << " is already dead..." << std::endl;
		return ;
	}
	std::cout << this->_name << " loses " << amount << " HP, going from " << this->_hp;
	this->_hp -= amount;
	if (this->_hp < 0)
		this->_hp = 0;
	std::cout << " to " << this->_hp << " !" << std::endl;
	if (this->_hp == 0)
		std::cout << this->_name << " is dead !    :(" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {

	if (this->_hp == 0)
	{
		std::cout << this->_name << " can't repair itself";
		std::cout << " because it's dead..." << std::endl;
		return ;
	}
	else if (this->_ep <= 0)
	{
		std::cout << this->_name << " can't repair itself";
		std::cout << " because it has no EP left..." << std::endl;
		return ;
	}
	std::cout << this->_name << " repairs for " << amount << " HP, going from " << this->_hp;
	this->_hp += amount;
	this->_ep--;
	std::cout << " to " << this->_hp << " !" << std::endl;
}