#include "Harl.hpp"

void Harl::complain(std::string level)
{
	void (Harl::*func[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	str[4] = {"debug", "info", "warning", "error"};
	bool flag = false;
	for (int i = 0; i < 4; i++)
	{
		if (str[i] != level && !flag)
			continue ;
		flag = true;
		switch (i) {
			case 0:
				(this->*func[0])();
				break ;
			case 1:
				(this->*func[1])();
				break ;
			case 2:
				(this->*func[2])();
				break ;
			case 3:
				(this->*func[3])();
				break ;
		}
	}
}

