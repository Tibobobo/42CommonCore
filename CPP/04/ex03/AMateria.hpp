#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

# include "ICharacter.hpp"

class AMateria {

	public:

		AMateria(void);
		AMateria(std::string const &type);
		AMateria(AMateria const &src);

		virtual ~AMateria(void);

		AMateria &operator=(AMateria const &rhs);

		std::string const &getType(void) const;
		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter &target);

	protected:

		std::string _type;

};

#endif