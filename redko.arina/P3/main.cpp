#include <iostream>
#include "getString.hpp"
#include "buildWithoutInt.hpp"

int main()
{
  int lenght = 0;
  char * str = redko::getString(std::cin, lenght);
  if (!str)
  {
    std::cerr << "Error: can't allocate memory for input string\n";
    delete[] str;
    return 1;
  }
  if (!str[0])
  {
    std::cerr << "Error: empty string\n";
    delete[] str;
    return 1;
  }
  char * strResult = redko::buildWithoutInt(str, lenght);
  if (!strResult)
  {
    std::cerr << "Error: can't allocate memory for result\n";
    delete[] str;
    return 1;
  }
  delete[] str;
  int i = 0;
  while (strResult[i] != '\0')
  {
    std::cout << strResult[i++];
  }
  std::cout << '\n';
  delete[] strResult;
  return 0;
}
