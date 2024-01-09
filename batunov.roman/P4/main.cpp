#include <iostream>
#include <string>
#include "readMatrixFromFile.hpp"
#include "readMatrixFromFilee.hpp"
#include "freeMatrix.hpp"
#include "longestCombin.hpp"
#include "writeResultToFile.hpp"
#include "writeArrayToFile.hpp"
#include "smoothMatrix.hpp"

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "Invalid number of arguments" << std::endl;
    return 1;
  }
  int num;
  try
  {
    num = std::stoi(argv[1]);
  }
  catch (const std::exception& e)
  {
    std::cerr << "Invalid number: " << argv[1] << std::endl;
    return 1;
  }
  if (num != 1 && num != 2)
  {
    std::cerr << "Invalid task number: " << num << std::endl;
    return 1;
  }
  std::string inputFilename = argv[2];
  std::string outputFilename = argv[3];
  int rows, cols;
  int** matrix;
  try
  {
    matrix = batunov::readMatrixFromFile(inputFilename, rows, cols);
  }
  catch (const std::exception& e)
  {
    std::cerr << "Failed to read matrix from file: " << e.what() << std::endl;
    return 2;
  }
  if (num == 1)
  {
    int result = batunov::longestCombin(matrix, rows, cols);
    try
    {
      batunov::writeResultToFile(outputFilename, result);
    }
    catch (const std::exception& e)
    {
      std::cerr << "Failed to write result to file: " << e.what() << std::endl;
      return 2;
    }
  }
  else if (num == 2)
  {
    double* smoothedMatrix = batunov::smoothMatrix(matrix, rows, cols);
    try
    {
      batunov::writeArrayToFile(smoothedMatrix, rows * cols, outputFilename);
    }
    catch (const std::exception& e)
    {
      std::cerr << "Failed to write array to file: " << e.what() << std::endl;
      return 2;
    }
    delete[] smoothedMatrix;
  }
  batunov::freeMatrix(matrix, rows);
  return 0;
}

