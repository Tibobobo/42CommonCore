#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <string>

class PresidentialPardonForm: public AForm {

	public:

		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &src);

		PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

		virtual ~PresidentialPardonForm(void);

		int execute(Bureaucrat const &executor) const;
		std::string getTarget(void) const;

	private:

		std::string _target;
};

#endif