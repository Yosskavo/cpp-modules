#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN
{
	private :
		std::stack<int> _stack;
	public :
		RPN(void);
		RPN(const RPN & r);
		RPN &operator=(const RPN & r);
		~RPN(void);
		int calculat_RPN(const std::string & s);
};

#endif
