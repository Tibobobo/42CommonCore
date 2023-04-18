#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class AForm {

    public:

        AForm(void);
        AForm(std::string const name, unsigned int const sGrade, unsigned int const eGrade);
        AForm(AForm const &src);

        virtual ~AForm(void);

        AForm &operator=(AForm const &rhs);

        std::string const getName(void) const;
        bool getSigned(void) const;
        unsigned int const getSGrade(void) const;
        unsigned int const getEGrade(void) const;

        bool    beSigned(Bureaucrat &b);
        bool    isExecutable(Bureaucrat const &b) const;
        virtual int execute(Bureaucrat const &executor) const = 0;


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

        class NotSignedException : public std::exception
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

std::ostream    &operator<<(std::ostream &o, AForm const &f);

#endif