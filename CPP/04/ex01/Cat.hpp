#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat :public Animal {

    public:

        Cat(void);
        Cat(Cat const &src);

        virtual ~Cat(void);

        Cat &operator=(Cat const &rhs);

        virtual void    makeSound(void) const;

        virtual Brain   *getBrain(void) const;
    
    private:

        Brain *_brain;
};



class WrongCat :public WrongAnimal {

    public:

        WrongCat(void);
        WrongCat(WrongCat const &src);

        virtual ~WrongCat(void);

        WrongCat &operator=(WrongCat const &rhs);

        void    makeSound(void) const;
};

#endif