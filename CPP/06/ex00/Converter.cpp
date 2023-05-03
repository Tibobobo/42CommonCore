#include "Converter.hpp"

Converter::Converter(void) {

	this->_c = 0;
	this->_i = 0;
	this->_f = 0;
	this->_d = 0;
	this->_overflow = false;
	this->_type = OTHER;
}

Converter::Converter(std::string str) {
	
	this->_overflow = false;
	if ((str.length() == 1 && isdigit(str[0]) == 0) || (str.length() == 3 && str[0] == 39 && str[2] == 39))
	{
		if (str.length() == 1)
			this->_c = str[0];
		else
			this->_c = str[1];
		this->_i = static_cast<int>(this->_c);
		this->_f = static_cast<float>(this->_c);
		this->_d = static_cast<double>(this->_c);
		this->_type = CHAR;
		return ;
	}
	this->_type = INT;
	bool point = false;
	size_t i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	if (str[i] == '\0')
		this->_type = OTHER;
	for (; i < str.length(); i++)
	{
		if (std::isdigit(str[i]))
			;
		else if (str[i] == '.' && point == false)
		{
			this->_type = DOUBLE;
			point = true;
		}
		else if (str[i] == '.' && point == true)
		{
			this->_type = OTHER;
			break;
		}
		else if (str[i] == 'f' && str[i + 1] == '\0')
		{
			this->_type = FLOAT;
			break;
		}
		else
		{
			this->_type = OTHER;
			break;
		}
	}
	if (this->_type == OTHER)
	{
		if (str.compare("inf") == 0 || str.compare("inff") == 0 || str.compare("+inf") == 0 || str.compare("+inff") == 0)
		{
			this->_overflow = true;
			this->_c = 127;
			this->_f = std::numeric_limits<float>::infinity();
			this->_d = std::numeric_limits<double>::infinity();
		}
		else if (str.compare("-inf") == 0 || str.compare("-inff") == 0)
		{
			this->_overflow = true;
			this->_c = 127;
			this->_f = std::numeric_limits<float>::infinity() * (-1);
			this->_d = std::numeric_limits<double>::infinity() * (-1);
		}
		else if (str.compare("nan") == 0 || str.compare("nanf") == 0)
		{
			this->_overflow = true;
			this->_c = 127;
			this->_f = std::numeric_limits<float>::quiet_NaN();
			this->_d = std::numeric_limits<double>::quiet_NaN();
		}
		else
			throw Converter::UnknownInput();
	}
	if (this->_type == INT && (str.length() > 11 || (str[0] == '-' && std::atoi(str.c_str()) >= 0) || str[0] != '-' && std::atoi(str.c_str()) < 0))
		this->_type = DOUBLE;
	if (this->_type == INT)
	{
		this->_i = std::atoi(str.c_str());
		if (this->_i >= 0 && this->_i < 127)
			this->_c = static_cast<char>(this->_i);
		else
			this->_c = 127;
		this->_f = static_cast<float>(this->_i);
		this->_d = static_cast<double>(this->_i);
	}
	if (this->_type == FLOAT || this->_type == DOUBLE)
	{
		this->_d = std::atof(str.c_str());
		this->_i = static_cast<int>(this->_d);
		if (this->_i >= 0 && this->_i < 127)
			this->_c = static_cast<char>(this->_i);
		else
			this->_c = 127;
		if (this->_d > 2147483647.0 || this->_d < -2147483648.0)
			this->_overflow = true;
		this->_f = static_cast<float>(this->_d);
	}
}

Converter::Converter(Converter const &src) {

	this->_c = src.getChar();
	this->_i = src.getInt();
	this->_f = src.getFloat();
	this->_d = src.getDouble();
	this->_overflow = src.getOverflow();
}

Converter::~Converter(void) {

}

Converter	&Converter::operator=(Converter const &rhs) {

	this->_c = rhs.getChar();
	this->_i = rhs.getInt();
	this->_f = rhs.getFloat();
	this->_d = rhs.getDouble();
	this->_overflow = rhs.getOverflow();
	return (*this);
}

char	Converter::getChar(void) const {

	return (this->_c);
}

int	Converter::getInt(void) const {

	return (this->_i);
}

float	Converter::getFloat(void) const {

	return (this->_f);
}

double	Converter::getDouble(void) const {

	return (this->_d);
}

bool	Converter::getOverflow(void) const {

	return (this->_overflow);
}

const char *Converter::UnknownInput::what(void) const throw() {

	return ("Unknown Input Exception");
}