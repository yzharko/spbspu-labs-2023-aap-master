#include "writeArrayToFile.hpp"
#include <stdexcept>
#include <iomanip>

void batunov::writeArrayToFile(double* array, int size, const std::string& filename)
{
  std::ofstream outputFile(filename);
  if (!outputFile.is_open())
  {
    throw std::runtime_error("Do not open the output file.");
  }
  for (int i = 0; i < size; i++)
  {
    outputFile << std::fixed << std::setprecision(1) << array[i] << " ";
  }
  outputFile.close();
}
