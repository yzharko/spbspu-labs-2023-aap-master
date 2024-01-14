#include <iostream>
#include <fstream>
#include <cstring>
#include "readMatrix.hpp"
#include "findMaxColumn.hpp"

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Wrong number of input parameters.\n";
    return 1;
  }

  if (strlen(argv[1]) != 1)
  {
    std::cerr << "First parameter is out of range.\n";
    return 1;
  }

  int task = 0;

  try
  {
    task = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "First parameter is not a number.\n";
    return 1;
  }

  if (task != 1 && task != 2)
  {
    std::cerr << "Task does not exist.\n";
    return 1;
  }

  std::ifstream input;
  input.open(argv[2]);

  int numberOfRows = 0;
  input >> numberOfRows;

  int numberOfColumns = 0;
  input >> numberOfColumns;

  if (!input)
  {
    std::cerr << "Cannot read matrix data.\n";
    return 2;
  }

  int numberOfValues = numberOfRows * numberOfColumns;
  int staticArray[10000] = { 0 };
  int * matrixValues = nullptr;

  matrixValues = (task == 1) ? staticArray : new int[numberOfValues];

  if (shagieva::readMatrix(input, matrixValues, numberOfValues) != numberOfValues)
  {
    std::cerr << "Number of matrix values is less than expected.\n";
    if (task == 2)
    {
      delete[] matrixValues;
    }
    return 2;
  }

  int result = 0;

  result = shagieva::findMaxColumn(matrixValues, numberOfRows, numberOfColumns);

  std::ofstream output;
  output.open(argv[3]);

  if (!output.is_open())
  {
    std::cerr << "Cannot open an output file.\n";
    if (task == 2)
    {
      delete[] matrixValues;
    }
    return 2;
  }

  output << result;

  if (task == 2)
  {
    delete[] matrixValues;
  }

  return 0;
}
