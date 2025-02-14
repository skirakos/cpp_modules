#include "Harl.hpp"

void Harl::debug (void) {
	std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"<<std::endl;
}

void Harl::info (void) {
	std::cout<<"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"<<std::endl;
}

void Harl::warning (void) {
	std::cout<<"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."<<std::endl;
}

void Harl::error (void) {
	std::cout<<"This is unacceptable! I want to speak to the manager now."<<std::endl;
}

void Harl::complain( std::string level ) {
	std::string complaints[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void(Harl::*actions[])(void)= {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int	i = 0;
	while (i <= 3 && level != complaints[i]) {
		i++;
	}
	if (i == 4) {
		std::cout << "Invalid input. " << std::endl;
		exit(1);
	}
	(this->*actions[i])(); //why this? it doesn't work without this
}