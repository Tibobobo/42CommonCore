#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <string>
# include <fstream>

class ShrubberyCreationForm: public AForm {

	public:

		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);

		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

		virtual ~ShrubberyCreationForm(void);

		int    execute(Bureaucrat const &executor) const;
		std::string getTarget(void) const;

	private:

		std::string _target;
};

#endif