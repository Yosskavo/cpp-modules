#include "Harl.hpp"

void Harl::complain(std::string level)
{
	void (Harl::*func[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	str[4] = {"debug", "info", "warning", "error"};
	for (int i = 0; i < 4; i++)
	{
		if (str[i] == level)
		{
			(this->*func[i])();
			return ;
		}
	}
}

