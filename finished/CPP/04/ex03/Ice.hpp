#ifndef ICE_HPP
# define ICE_HPP

# include <string>
# include "AMateria.hpp"

class Ice :public AMateria {

	public:

		Ice(void);
		Ice(Ice const &src);

		virtual ~Ice(void);

		Ice &operator=(Ice const &rhs);

		std::string const &getType(void) const;
		Ice* clone(void) const;
		void use(ICharacter &target);

};

#endif