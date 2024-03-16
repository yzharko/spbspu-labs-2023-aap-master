#include "EQUAL_CHARS_FINDER.hpp"
#include <iostream>
size_t rejepbayev::counterOfEqualPairs(char* values, int real_size)
{
  int count = 0;
  for (int i = 0; i < real_size; i++)
    for (int j = i + 1; j < real_size; j++)
    {
      count += (values[i] == values[j]);
    }
  return count;
}
char* rejepbayev::readLine(size_t& real_size)
{
  size_t max_size = 10;
  char* line = new char[max_size];
  char current_char = '0';
  std::cin >> std::noskipws;
  while (std::cin >> current_char && current_char != '\n')
  {
    if(real_size >= max_size)
    {
      char* new_line = new char[max_size * 2];
      if (!new_line)
      {
        delete[] line;
        throw std::logic_error("Error: not enough space\n");
      }
      for (size_t i = 0; i < max_size; i++)
      {
        new_line[i] = line[i];
      }
      max_size *= 2;
      delete[] line;
      line = new_line;
    }
    line[real_size] = current_char;
    real_size++;
  }
  if (!real_size)
  {
    delete[] line;
    throw std::logic_error("Error: zero sequence\n");
  }
  std::cin >> std::noskipws;
  return line;
}
