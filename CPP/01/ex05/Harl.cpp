#include "Harl.hpp"

Harl::Harl(void) {

    return ;
}

Harl::~Harl(void) {

    return ;
}

void    Harl::complain(std::string level) {

    void        (Harl::*fun_ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
		if (levels[i] == level)
		{
			(this->*fun_ptr[i])();
			break ;
		}
}

void    Harl::debug(void) {

    std::cout << "DEBUG : I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !\n"; 
}

void    Harl::info(void) {

    std::cout << "INFO : I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !\n";

}

void    Harl::warning(void) {

    std::cout << "WARNING : I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";

}

void    Harl::error(void) {

    std::cout << "ERROR : This is unacceptable ! I want to speak to the manager now.\n";
}