#include <iostream>
#include "inputString.hpp"
#include "formingNewString.hpp"

int main()
{
  using namespace sukacheva;
  size_t secondStringSize = 5;
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
  char* secondString = new char[secondStringSize] {'g', '1', 'h', '2', 'k'};
  char * result = formingNewString(firstString, secondString, firstStringSize, secondStringSize);
  std::cout << result << "\n";
  delete[] firstString;
  delete[] secondString;
  delete[] result;
  return 0;
}
