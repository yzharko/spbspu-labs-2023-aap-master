#include <iostream>
#include "exp.hpp"
#include "funcs.hpp"
#include "read.hpp"

int main()
{
  int lenght = 0;
  char * str = susidko::getString(std::cin, lenght);
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
  char * strResult = susidko::replaceUpLow(str, lenght);
  int countChars = susidko::countDiffLetters(str);
  if (!strResult)
  {
    std::cerr << "Error: can't allocate memory for result\n";
    delete[] str;
    return 1;
  }
  delete[] str;
  for (int i = 0; strResult[i] != '\0' ;i++)
  {
    std::cout << strResult[i];
  }
  std::cout << '\n';
  delete[] strResult;
  std::cout << countChars;
  std::cout << '\n';
  return 0;
}
