#include "Contact.hpp"

class PhoneBook
{
	private :
		Contact	contact[8];
		int	index;
	public :	
		int	add_contact(Contact &contact);
		int	search_contact(Contact contact);
		// int x
};
