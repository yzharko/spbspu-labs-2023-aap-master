#include <iostream>
#include "function.hpp"

int main()
{
  using namespace gorbunova;
  LatRemove LatinRemove;
  char c;
  int len = 0;
  const int add = 15;
  char *input = new char[add];
  std::cin >> std::noskipws;
  do
  {
    std::cin >> c;
    input[len++] == c;
    if (len % add == 0)
    {
      char *inputNew = new char[len + add];
      for (int i = 0; i < len; i++)
      {
        inputNew[i] = input[i];
      }
      delete[] input;
      input = inputNew;
    }
  }
  while (c != '\n');
  std::cin >> std::skipws;
  char *result = new char[len]{}
  LatinRemove(result, input, &len);
  std::cout << result;
  delete[] input;
  delete[] result;
}
