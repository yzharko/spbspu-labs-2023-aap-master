#include "newLine.hpp"
#include <iostream>

char * popov::newLine(int & len)
{
  int count = 1;
  const int add = 15;
  char * input = new char[add]{};
  std::cin >> std::noskipws;
  char c;
  do
  {
    std::cin >> c;
    input[len++] = c;
    if (len - (add * count) == 0)
    {
      ++count;
      char * biggerinput = new char[add + len];
      for(int i = 0; i < len; i++)
      {
        biggerinput[i] = input[i];
      }
      delete [] input;
      input = biggerinput;
    }
  }while (c != '\n');
  std::cin >> std::skipws;
  return input;
}
