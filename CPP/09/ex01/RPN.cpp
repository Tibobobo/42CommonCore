# include "RPN.hpp"

RPN::RPN(std::string str) : _str(str) {

}

RPN::~RPN(void) {

}

void RPN::calculate(void) {

    if (_str.length() == 1 && std::isdigit(*_str.begin()))
    {
        std::cout << _str << std::endl;
        exit (0);
    }
    if (checkFormat(_str) == false)
    {
        std::cout << "Error" << std::endl;
		exit (-1);
    }
    int a = 0;
    int b = 0;
    for (std::string::iterator it = _str.begin(); it != _str.end(); it++)
    {
        if (std::isdigit(*it))
            _numbers.push(*it - '0');
        else if (isOperator(*it) == true)
        {
            if (_numbers.size() < 2)
            {
                std::cout << "Error" << std::endl;
		        exit (-1);
            }
            a = _numbers.top();
            _numbers.pop();
            b = _numbers.top();
            _numbers.pop();
            _numbers.push(operation(a, b, *it));
        }
    }
    std::cout << _numbers.top() << std::endl;
}

bool	RPN::isOperator(char c) const {

	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

bool	RPN::checkFormat(std::string str) const {

	int num = 0;
	int op = 0;
	if (!std::isdigit(str[0]) || !isOperator(str[str.length() - 1]))
		return (false);
	for (std::string::iterator it = str.begin(); it != str.end(); it++)
	{
		if (*it == ' ' && ((it + 1) != str.end() && *(it + 1) != ' '))
			;
		else if (std::isdigit(*it) && *(it + 1) == ' ')
			num++;
		else if (isOperator(*it))
		{
			op++;
			if (it + 1 != str.end() && *(it + 1) != ' ')
				return (false);
		}
		else
			return (false);
	}
	if (num - op != 1)
		return (false);
	return (true);
}

int		RPN::operation(int a, int b, char op) const {

    if (op == '+')
        return (b + a);
    else if (op == '-')
        return (b - a);
    else if (op == '*')
        return (b * a);
    else
    {
        if (a == 0)
        {
            std::cout << "[1]     42424242 floating point exception (core dumped)   ./RPN \"" << _str << "\"         ";
            std::cout << "Nah just kidding, but please don't try dividing by 0 =)" << std::endl;
            exit (-1);
        }
        return (b / a);
    }
}