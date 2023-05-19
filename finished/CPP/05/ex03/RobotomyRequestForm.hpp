#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <string>

class RobotomyRequestForm: public AForm {

	public:

		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &src);

		RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

		virtual ~RobotomyRequestForm(void);

		int    execute(Bureaucrat const &executor) const;
		std::string getTarget(void) const;

	private:

		std::string _target;
};

#endif