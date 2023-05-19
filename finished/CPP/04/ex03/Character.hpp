#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character: public ICharacter {

	public:

		Character(void);
		Character(std::string name);
		Character(Character const &src);

		virtual ~Character(void);

		Character &operator=(Character const &rhs);

		std::string const &getName(void) const;
		AMateria const *getMateria(int idx) const;
		void	equip(AMateria *m);
		void	unequip(int idx);
		void	use(int idx, ICharacter &target);

	private:

		std::string _name;
		AMateria	*_inv[4];
};

#endif