#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Form;

class Bureaucrat {

    public:

        Bureaucrat(void);
        Bureaucrat(std::string const name, unsigned int grade);
        Bureaucrat(Bureaucrat const &src);

        ~Bureaucrat(void);

        Bureaucrat &operator=(Bureaucrat const &rhs);

        std::string const getName(void) const;
        unsigned int getGrade(void) const;
        void    upgrade(void);
        void    downgrade(void);
        bool    signForm(Form &f);

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
        unsigned int _grade;
        void    setGrade(unsigned int grade);

};

std::ostream    &operator<<(std::ostream &o, Bureaucrat const &b);

#endif