#include "dgt_snd.hpp"

void kovshikov::withDigits(char * string1, char * string2, char * output, size_t readStr2, size_t readStr1)
{
  for(size_t i = 0; i < readStr1; i++)
  {
    output[i] = string1[i];
  }
  size_t num = readStr1 - 1;
  for(size_t i = 0; i < readStr2; i++)
  {
    if(std::isdigit(string2[i]))
    {
      output[num++] = string2[i];
    }
  }
};
