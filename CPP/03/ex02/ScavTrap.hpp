#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap :public ClapTrap {

    public:
        ScavTrap(void);
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const &src);

	    ~ScavTrap(void);

	    ScavTrap	&operator=(ScavTrap const &rhs);

        void    attack(const std::string &target);
        bool    getGuard(void) const;
        void    guardGate(void);

    private:

        bool _guard;
};


#endif