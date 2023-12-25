#include "writeResultToFile.hpp"
#include <stdexcept>

void batunov::writeResultToFile(const std::string& filename, int result)
{
  std::ofstream outputFile(filename);
  if (!outputFile.is_open())
  {
    throw std::runtime_error("Do not open the output file.");
  }
  outputFile << result;
  outputFile.close();
}
