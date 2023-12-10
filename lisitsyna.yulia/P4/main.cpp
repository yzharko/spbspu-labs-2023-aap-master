#include <iostream>
#include <fstream>
#include <string>
#include "princdiag.hpp"

using namespace lisitsyna;
int main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cerr << "Incorrectly entered data" << "\n";
		return 1;
	}
	int num;
	try
	{
		int num = std::stoll(argv[1]);
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << "Please enter a valid value" << "\n";
		return 1;
	}
	// argv[2] имя файла с матрицей 
	if (num > 2 || num <= 0)
	{
		std::cerr << "Incorrect value" << "\n";
		return 2;
	}
	int rows = 0, cols = 0;
	std::ifstream input(argv[2]);
	input >> rows >> cols;
	if (!input)
	{
		std::cerr << "Cannot read the file" << "\n";
		return 2;
	}
	if (input.eof())
	{
		std::cerr << "File is empty" << "\n";
		return 2;
	}
	principal aboba;
	int* values;
	if (num == 1)
	{
		int static_[10000] = { 0 };
		aboba.arraay(rows, cols, input,values);
		values = static_;
	}
	if (num == 2)
	{
		int * dinamo_ = new int[rows * cols];
		values = dinamo_;
		try
		{
			aboba.arraay(rows, cols, input, values);
			delete[] dinamo_;
		}
		catch (std::logic_error const & e)
		{
			std::cerr << e.what();
			delete[] dinamo_;
			return 2;
		}
	}
}