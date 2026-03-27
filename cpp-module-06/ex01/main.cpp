#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data *some = new Data;
	uintptr_t	test;

	some->a = 10;
	some->b = 11;
	test = Serializer::serialize(some);
	std::cout << "this is the return of serialize " << some << std::endl; 
	std::cout << "this is the return of deserialize " << Serializer::deserialize(test) << std::endl; 
}
