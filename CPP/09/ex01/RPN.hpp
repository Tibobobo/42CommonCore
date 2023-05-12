#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class RPN {

	public:

		RPN(std::string str);
		~RPN(void);

	private:

		RPN(void);
		RPN(RPN const &src);
		RPN &operator=(RPN const &rhs);
		std::stack<int> _numbers;
};

#endif