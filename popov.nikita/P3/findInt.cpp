#include "findInt.hpp"
#include <cctype>

void popov::FindInt::operator()(char * result, char * input, int * num)
{
  int a = 0;
  for (int i = 0; i < *num; i++)
  {
    if (isdigit(input[i]) == 0)
    {
      result[a++] = input[i];
    }
  }
}
