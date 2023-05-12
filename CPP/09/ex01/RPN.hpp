#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class RPN {

	public:

		RPN(std::string str);
		~RPN(void);

		void calculate(void);
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