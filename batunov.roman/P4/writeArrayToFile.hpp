#ifndef WRITE_ARRAY_TO_FILE_HPP
#define WRITE_ARRAY_TO_FILE_HPP
#include <fstream>
#include <string>

namespace batunov
{
  void writeArrayToFile(double* array, int size, const std::string& filename);
}

#endif
