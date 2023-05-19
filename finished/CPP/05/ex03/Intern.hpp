#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>

class AForm;

class Intern {

    public:

        Intern(void);
        Intern(Intern const &src);

        ~Intern(void);

        Intern &operator=(Intern const &rhs);

        AForm *makeForm(std::string const type, std::string const formTarget) const;

    private:

};

#endif