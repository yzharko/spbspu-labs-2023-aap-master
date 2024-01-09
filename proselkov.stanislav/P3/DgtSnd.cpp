#include "DgtSnd.hpp"

void DgtSnd(char * input1, char * input2, char * output, size_t read1, size_t read2)
{
  for(size_t i = 0; i < read1; i++)
  {
    output[i] = input1[i];
  }
  size_t num = read1 - 1;
  for(size_t i = 0; i < read2; i++)
  {
    if(std::isdigit(input2[i]))
    {
      output[num++] = input2[i];
    }
  }
};
