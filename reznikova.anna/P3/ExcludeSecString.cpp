#include "ExcludeSecString.hpp"

char * reznikova::ExcludeSecString(char* first_str, char* sec_str, size_t first_size, size_t sec_size)
{
  char* result_string = new char[first_size+1]();
  size_t read = 0;
  for (size_t i = 0; i < first_size; i++)
  {
    int flag = 0;
    for (size_t j = 0; j < sec_size; j++)
    {
      if (first_str[i] == sec_str[j])
      {
        flag = 1;
        break;
      }
    }
    if (flag == 0)
    {
      result_string[read++] = first_str[i];
    }
  }
  result_string[read] = '\0';
  return result_string;
}
