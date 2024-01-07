#include <iostream>
#include "setLine.hpp"
#include "frqtopLine.hpp"
#include "excsndLine.hpp"

int main()
{
  size_t userAddSize = 10;
  size_t userStringLength = 0;
  char * userString = khoroshkin::inputLine(std::cin, userStringLength, userAddSize);
  const char * givenString = "abc";

  if (userStringLength < 4)
  {
    std::cerr << "Error: Too short string\n";
    delete[] userString;
    return 1;
  }

  try
  {
    char * newString = new char[userStringLength + 1];
    khoroshkin::getFrequency(userString, userStringLength, newString);
    std::cout << "Result for FRQ-TOP: " << newString << '\n';
    khoroshkin::generateNewWithTwo(userString, givenString);
    std::cout << "Result for EXC-SND: " << userString << '\n';
    delete[] newString;
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Error: Cannot allocate memory\n";
    delete[] userString;
    return 1;
  }
  delete[] userString;
  return 0;
}
