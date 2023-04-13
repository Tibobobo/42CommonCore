#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {

	public:

		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &src);

		~ClapTrap(void);

		ClapTrap	&operator=(ClapTrap const &rhs);

		std::string	getName(void) const;
		int			getHp(void) const;
		int			getEp(void) const;
		int			getAtk(void) const;

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);


	protected:

		std::string	_name;
		int			_hp;
		int			_ep;
		int			_atk;
};

#endif
