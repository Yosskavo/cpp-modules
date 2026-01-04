#include "Contact.hpp"

class PhoneBook
{
	private :
		Contact 	contact[8];
		short		saved_contact;
		short		index;
	public :
		bool getContact(void);
		bool setContact(void);
		void RefrechIndex(bool flag);
};
