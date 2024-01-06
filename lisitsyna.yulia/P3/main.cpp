#include <iostream>
#include <iomanip>
#include "whitespace.hpp"

int main(
{
	using namespace lisitsyna;
        char* input = new char[100] {};
        drop string;
        size_t ipt = string.str_space(input);
        std::cin.getline(input, 100);
	std::cout << string.omit(input) << "\n";
	delete[] input;
	return 0;
}
