#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <cstdlib>

class RPN {

	public:

		RPN(std::string str);
		~RPN(void);

		bool calculate(void);
		bool	checkFormat(std::string str) const;
		bool	isOperator(char c) const;
		int		operation(int a, int b, char op) const;

	private:

		RPN(void);
		RPN(RPN const &src);
		RPN &operator=(RPN const &rhs);
		std::stack<int> _numbers;
		std::string _str;
};

#endif