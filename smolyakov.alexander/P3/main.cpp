#include <iostream>
#include <stdexcept>
#include "dynamicStringReader.hpp"
#include "repeatingDigitsCheck.hpp"

int main()
{
  using namespace cringecode;
  DynamicStringReader stringReader = DynamicStringReader(10);
  char* string;
  try
  {
    string = stringReader.read(std::cin);
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Could not allocate memory for the string. Detais: " << e.what() << '\n';
    return 1;
  }
  try
  {
    if (containsRepeatingDigits(string, stringReader.getLength()))
    {
      std::cout << '1' << '\n';
    }
    else
    {
      std::cout << '0' << '\n';
    }
  }
  catch (const std::logic_error& e)
  {
    std::cerr << "Could not count repeating digits. Details: " << e.what() << '\n';
    return 2;
  }
  return 0;
}
