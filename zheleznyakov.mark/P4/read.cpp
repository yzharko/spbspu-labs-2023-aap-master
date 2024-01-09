#include <cstring>
#include "functions.hpp"

int zheleznyakov::stringToInt(char * str)
{
  for (size_t i = 0; i < std::strlen(str); i++)
  {
    if (!(std::isdigit(str[i])))
    {
      throw std::invalid_argument("Error: The task number is not an numeric.\n");
    }
  }
  return std::stoll(str);
}

int zheleznyakov::readMatrix(std::ifstream & input, int * matrix, int columns, int rows)
{
  int count = 0;
  for (int i = 0; i < columns * rows; i++)
  {
    input >> matrix[i];
    count++;
    if (!input)
    {
      throw std::runtime_error("Error: The Matrix is broken.\n");
    }
  }
  return count;
}
