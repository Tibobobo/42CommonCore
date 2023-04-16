#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class Form {

    public:

        Form(void);
        Form(std::string const name, unsigned int const sGrade, unsigned int const eGrade);
        Form(Form const &src);

        ~Form(void);

        Form &operator=(Form const &rhs);

        std::string const getName(void) const;
        bool getSigned(void) const;
        unsigned int const getSGrade(void) const;
        unsigned int const getEGrade(void) const;

        bool    beSigned(Bureaucrat &b);


        class GradeTooLowException : public std::exception
	    {
	        public:
		        virtual const char *what() const throw();
	    };

	    class GradeTooHighException : public std::exception
	    {
	        public:
		        virtual const char *what() const throw();
	    }; 

    private:

        std::string const _name;
        bool _signed;
        unsigned int const _sGrade;
        unsigned int const _eGrade;
};

std::ostream    &operator<<(std::ostream &o, Form const &f);

#endif