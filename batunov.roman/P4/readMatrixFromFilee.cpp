#include "readMatrixFromFilee.hpp"
#include <stdexcept>

int** batunov::readMatrixFromFilee(const std::string& filename, int& rows, int& cols)
{
  std::ifstream inputFile(filename);
  if (!inputFile.is_open())
  {
    throw std::runtime_error("Do not open the input file.");
  }
  inputFile >> rows >> cols;
  int** matrix = new int* [rows];
  for (int i = 0; i < rows; i++)
  {
    matrix[i] = new int[cols];
    for (int j = 0; j < cols; j++)
    {
      inputFile >> matrix[i][j];
    }
  }
  inputFile.close();
  return matrix;
}
