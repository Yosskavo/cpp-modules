// #include <iostream>
#include <string>

class Contact 
{
	private :
		std::string	last_name;
		std::string	phone_number;
		std::string	darkest_secret;
		std::string	nickname;
		std::string	first_name;
	public :
		std::string	get_phone_number();
		std::string	set_phone_number();
		std::string	get_darkset_secret();
		std::string	set_darkset_secret();
		std::string	get_nickname();
		std::string	set_nickname();
		std::string	get_last_name();
		std::string	set_last_name();
		std::string	get_first_name();
		std::string	set_first_name();
};
