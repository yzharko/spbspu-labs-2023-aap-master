#include <iostream>
#include "function.hpp"

int main()
{
  const int MAX_LENGTH = 100;
  char input[MAX_LENGTH];
  std::cin.getline(input, MAX_LENGTH);

  try
  {
    function(input);
    std::cout << input << std::endl;
  }
  catch (...)
  {
    std::cerr << "Error: Unable to allocate memory." << std::endl;
    return 1;
  }
  return 0;
}
