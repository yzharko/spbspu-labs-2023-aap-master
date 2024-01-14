#include "dgt_snd.hpp"

void kovshikov::withDigits(char * userString, const char * myString, char * output, size_t length, size_t read)
{
  for(size_t i = 0; i < read; i++)
  {
    output[i] = userString[i];
  }
  size_t num = read - 1;
  for(size_t i = 0; i < length; i++)
  {
    if(std::isdigit(myString[i]))
    {
      output[num++] = myString[i];
    }
  }
};
