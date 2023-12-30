#include "functionDgtSnd.h"
#include <iostream>
#include <cctype>

char* appendNumToStr(char* str1, char* str2)
{
		char* dest = new char();
		char* dest_ = dest;

		while (*str1)
		{
				*dest++ = *str1++;
		}

		std::cout << dest << std::endl;

		while (*str2)
		{
				if (std::isdigit(*str2))
				{
						*dest++ = *str2;
				}
				++str2;
		}

		*dest += '\0';

		return dest_;
}
