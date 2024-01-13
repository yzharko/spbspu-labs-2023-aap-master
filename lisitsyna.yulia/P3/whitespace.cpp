#include "whitespace.hpp"
#include <iostream>
#include <string>

namespace lisitsyna
{
	size_t drop::str_space(char* input)
	{
		std::cin >> std::noskipws;
		while (std::cin >> c)
		{
			input[read++] = c;
			str += c;
			if (c == '\n')
			{
				input[read - 1] = 0;
				break;
			}
		}
		std::cin >> std::skipws;
		return reads;
	}
	size_t drop::omit(std::string str)
	{
		int k = 0;
		std::string tmp = "";
		for (int i = 0; i < str.length() - 1; i++)
			if (str[i + 1] == str[i] && str[i + 1] == ' ')
				k++;
			else {
				tmp += str[i];
				str = tmp;
				return k;
			}
	}
}
