#include <iostream>
#include <fstream>
#include "ArrayProcessing.hpp"

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Error: should contain 4 parameters\n";
    return 1;
  }
  int num;
  if (!(khoroshkin::isNumber(argv[1])))
  {
    std::cerr << "Error: first parameter can accept only 1 or 2\n";
    return 1;
  }
  else
  {
    num = std::stoll(argv[1]);
  }
  int statMatrix[1000] = { 0 };
  int * dynMatrix = nullptr;
  try
  {
    int Rows, Cols;
    std::ifstream inputFile(argv[2]);
    khoroshkin::fillingRowsAndCols(inputFile, Rows, Cols);
    std::ofstream outputFile(argv[3]);
    int successOrNo;
    if (num > 2 || num < 1)
    {
      std::cerr << "Error: I can accept only 1 or 2\n";
      return 1;
    }
    else if (num == 1)
    {
      successOrNo = khoroshkin::inputArray(inputFile, statMatrix, Rows * Cols);
      if (successOrNo != Rows*Cols)
      {
        throw std::invalid_argument("Error: was filled only " + std::to_string(successOrNo+1) + " elements");
      }
      khoroshkin::fillingOutputFile(outputFile, statMatrix, Rows, Cols);
    }
    else
    {
      int * dynMatrix = new int[Rows * Cols];
      int successOrNo = khoroshkin::inputArray(inputFile, dynMatrix, Rows * Cols);
      if (successOrNo != Rows*Cols)
      {
        delete[] dynMatrix;
        throw std::runtime_error("Error: was filled only " + std::to_string(successOrNo+1) + " elements");
      }
      khoroshkin::fillingOutputFile(outputFile, dynMatrix, Rows, Cols);
      delete[] dynMatrix;
    }
  }
  catch (const std::runtime_error & e)
  {
    std::cerr << e.what();
    return 2;
  }
  catch (const std::logic_error & e)
  {
    std::cerr << e.what();
    if (dynMatrix)
    {
      delete[] dynMatrix;
    }
    return 2;
  }
  return 0;
}
