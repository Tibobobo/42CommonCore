#include "Character.hpp"

// Character

Character::Character(void) {

	this->_name = "DefaultName";
	for (int i = 0; i < 4; i++)
		this->_inv[i] = NULL;
}

Character::Character(std::string name) {

	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_inv[i] = NULL;
}

Character::Character(Character const &src) {

	this->_name = src.getName();
	for (int i = 0; i < 4; i++)
	{
		AMateria const *temp = src.getMateria(i);
		if (temp == NULL)
			this->_inv[i] = NULL;
		else
			this->_inv[i] = temp->clone();
	}
}

Character::~Character(void) {

	for (int i = 0; i < 4; i++)
	{
		if (this->_inv[i] != NULL)
			delete this->_inv[i];
	}
}

Character	&Character::operator=(Character const &rhs) {

	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_inv[i] != NULL)
				delete this->_inv[i];
		}
		this->_name = rhs.getName();
		for (int i = 0; i < 4; i++)
		{
			AMateria const *temp = rhs.getMateria(i);
			if (temp == NULL)
				this->_inv[i] = NULL;
			else
				this->_inv[i] = temp->clone();
		}
	}
	return (*this);
}

std::string const &Character::getName(void) const {

	return (this->_name);
}

AMateria const *Character::getMateria(int idx) const {

	if (idx < 0 || idx > 3)
		return (NULL);
	return (this->_inv[idx]);
}

void	Character::equip(AMateria *m) {

	for (int i = 0; i < 4; i++)
	{
		if (this->_inv[i] == NULL)
		{
			this->_inv[i] = m;
			return;
		}
	}
}

void	Character::unequip(int idx) {

	if (idx < 0 || idx > 3)
		return ;
	this->_inv[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target) {

	if (idx < 0 || idx > 3 || this->_inv[idx] == NULL)
		return ;
	this->_inv[idx]->use(target);
}