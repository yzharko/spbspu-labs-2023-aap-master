#include <iostream>
#include <iomanip>
#include "funct.hpp"

int main()
{
  using namespace sadofeva;
  char* input = new char[100] {};
  Str string;
  try
  {
    size_t ipt = string.Str_read(input);
    std::cout << string.Hr(input) << "\n";
    delete[] input;
    return 0;
  }
  catch (std::logic_error const & e)
  {
    std::cerr << e.what() << "\n";
    return 2;
  }
}
