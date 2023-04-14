#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>

# include "AMateria.hpp"
# include "IMateriasource.hpp"

class MateriaSource :public IMateriaSource {

	public:

		MateriaSource(void);
		MateriaSource(MateriaSource const &src);

		virtual ~MateriaSource(void);

		MateriaSource &operator=(MateriaSource const &rhs);

		AMateria *getMateria(int idx) const;
		void	learnMateria(AMateria *m);
		AMateria* createMateria(std::string const & type);

	private:

		AMateria *_materia[4];

};

#endif