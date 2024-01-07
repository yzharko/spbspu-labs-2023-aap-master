#include <iostream>
#include "findInt.hpp"

int main()
{
  using namespace popov;
  FindInt FindInteger;
  const int add = 15;
  char * input = new char[add]{};
  char c;
  int len = 0;
  int count = 1;
  std::cin >> std::noskipws;
  do
  {
    std::cin >> c;
    input[len++] = c;
    if (len - (add * count) == 0)
    {
      ++count;
      char * newinput = new char[add + len];
      for(int i = 0; i < len; i++)
      {
        newinput[i] = input[i];
      }
      delete [] input;
      input = newinput;
    }
  }while (c != '\n');
  std::cin >> std::skipws;
  char * result = new char[len]{};
  FindInteger(result, input, &len);
  std::cout << result;
  delete [] input;
  delete [] result;
}
