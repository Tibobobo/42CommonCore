#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class   HumanA {

    public:

        HumanA(std::string name, Weapon &w);
        ~HumanA(void);

        void    attack(void) const;

    private:

        std::string _name;
        Weapon  &_w;
};

#endif