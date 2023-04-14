#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {

	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src) {

	for (int i = 0; i < 4; i++)
	{
		AMateria const *temp = src.getMateria(i);
		if (temp == NULL)
			this->_materia[i] = NULL;
		else
			this->_materia[i] = temp->clone();
	}
}

MateriaSource::~MateriaSource(void) {

	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] != NULL)
			delete this->_materia[i];
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs) {

	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_materia[i] != NULL)
				delete this->_materia[i];
		}
		for (int i = 0; i < 4; i++)
		{
			AMateria const *temp = rhs.getMateria(i);
			if (temp == NULL)
				this->_materia[i] = NULL;
			else
				this->_materia[i] = temp->clone();
		}
	}
	return (*this);
}

AMateria *MateriaSource::getMateria(int idx) const {

	if (idx < 0 || idx > 3)
		return (NULL);
	return (this->_materia[idx]);
}

void	MateriaSource::learnMateria(AMateria *m) {

	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] == NULL)
		{
			this->_materia[i] = m;
			return;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const & type) {

	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] != NULL && this->_materia[i]->getType() == type)
			return (this->_materia[i]->clone());
	}
	return (NULL);
}