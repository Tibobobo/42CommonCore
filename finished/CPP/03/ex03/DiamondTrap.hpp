#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap :public ScavTrap, public FragTrap {

    public:
        DiamondTrap(void);
        DiamondTrap(std::string name);
        DiamondTrap(DiamondTrap const &src);

	    virtual ~DiamondTrap(void);

	    DiamondTrap	&operator=(DiamondTrap const &rhs);

        void    attack(const std::string &target);
        void    whoAmI(void);

        std::string getName(void) const;
    
    private:
        std::string _name;
};


#endif