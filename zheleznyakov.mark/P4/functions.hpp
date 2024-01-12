#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <fstream>

namespace zheleznyakov
{
  int stringToInt(char * str);
  int readMatrix(std::ifstream & input, int * matrix, int columns, int rows);
  int findMaxRowInMatrix(const int * matrix, int columns, int rows);
};
#endif
