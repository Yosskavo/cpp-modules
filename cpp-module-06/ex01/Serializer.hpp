#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include "Data.hpp"

class Serializer
{
	private :
		Serializer(void);
		~Serializer(void);
		Serializer & operator=(const Serializer & s);
		Serializer(const Serializer & s);
	public :
		static uintptr_t		serialize(Data* ptr);
		static Data*			deserialize(uintptr_t raw);
};

#endif
