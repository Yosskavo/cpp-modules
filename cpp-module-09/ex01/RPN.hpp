#ifndef RPN_HPP
#define RPN_HPP

#include <string>

class RPN
{
	private :

	public :
		RPN(void);
		RPN(const RPN & r);
		RPN &operator=(const RPN & r);
		~RPN(void);
		int calculat_RPN(const std::string & s);
};

#endif
