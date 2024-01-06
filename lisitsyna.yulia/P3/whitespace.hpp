#ifndef WHITESPACE_HPP
#define WHITESPACE_HPP

namespace lisitsyna
{
	class drop
	{
	public:
		size_t str_space(char* inpt);
		size_t omit(std::string str);
	private:
		char reads = 0;
		char c = 0;
		size_t read = 0;
		std::string str;
	};
}

#endif
