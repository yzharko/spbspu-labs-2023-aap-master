#include <iostream>
#include "inputString.hpp"
#include "formingNewString.hpp"

int main()
{
  using namespace sukacheva;
  size_t firstStringSize = 0;
  char* firstString = nullptr;
  try
  {
    firstString = inputString(std::cin, firstStringSize);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    delete[] firstString;
    return 1;
  }
  const char secondString[5] = {'g', '1', 'h', '2', 'k'};
  char * result = formingNewString(firstString, secondString, firstStringSize, 5);
  std::cout << result << "\n";
  delete[] firstString;
  delete[] result;
  return 0;
}
