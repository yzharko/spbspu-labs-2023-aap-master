#include <iostream>
#include <stdexcept>
#include <cstring>
#include "findCommonChars.hpp"
#include "readLine.hpp"

int main()
{
  using namespace hohlova;
  size_t maxCharNum = 10;
  size_t size = 0;
  char* inputStr = hohlova::readLine(std::cin, size, maxCharNum);
  size_t inputLength = strlen(inputStr);
  if (inputLength == 0)
  {
    std::cerr << "error: empty line\n";
    delete[] inputStr;
    return 1;
  }
  std::cout << findCommonChars(inputStr, size);
  delete[] inputStr;
  return 0;
}
