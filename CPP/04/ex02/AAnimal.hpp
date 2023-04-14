#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class AAnimal {

    public:

        AAnimal(void);
        AAnimal(AAnimal const &src);

        virtual ~AAnimal(void);

        AAnimal  &operator=(AAnimal const &rhs);

        std::string getType(void) const ;

        virtual void    makeSound(void) const = 0;

    protected:

        std::string _type;
};

#endif