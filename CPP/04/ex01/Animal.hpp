#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class Animal {

    public:

        Animal(void);
        Animal(Animal const &src);

        virtual ~Animal(void);

        Animal  &operator=(Animal const &rhs);

        std::string getType(void) const ;

        virtual void    makeSound(void) const;

    protected:

        std::string _type;
};



class WrongAnimal {

    public:

        WrongAnimal(void);
        WrongAnimal(WrongAnimal const &src);

        virtual ~WrongAnimal(void);

        WrongAnimal  &operator=(WrongAnimal const &rhs);

        std::string getType(void) const ;

        void    makeSound(void) const;

    protected:

        std::string _type;
};

#endif