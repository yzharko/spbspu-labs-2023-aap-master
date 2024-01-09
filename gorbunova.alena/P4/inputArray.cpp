#include "inputArray.hpp"
#include <iostream>
#include <fstream>

int gorbunova::readFixedSizeArray(const char* fileName, int(&fixedArray)[100][100], int& rows, int& cols)
{
  std::ifstream inputFile(fileName);
  if(!inputFile.is_open())
  {
    std::cerr << "Unable to open file" << fileName << "\n";
    return 2;
  }
  inputFile >> std::ws;
  if (inputFile.eof())
  {
    std::cerr << "File is empty\n";
    return 2;
  }
  if (!(inputFile >> rows >> cols))
  {
    std::cerr << "Failed to read rows or cols from the file\n";
    inputFile.close();
    return 2;
  }
  if (rows * cols > 100000)
  {
    std::cerr << "Array size exceeds maximum limit\n";
    inputFile.close();
    return 2;
  }
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (!(inputFile >> fixedArray[i][j]))
      {
        std::cerr << "Invalid data\n";
        inputFile.close();
        return 2;
      }
    }
  }
  int temp;
  if (inputFile >> temp)
  {
    std::cerr << "Too many elements in the matrix\n";
    inputFile.close();
    return 2;
  }
  inputFile.close();
  return 0;
}
int gorbunova::readDynamicSizeArray(const char* fileName, int**& dynamicArray, int& rows, int& cols)
{
  std::ifstream inputFile(fileName);
  if(!inputFile.is_open())
  {
    std::cerr << "Unable to open file" << fileName << "\n";
    return 2;
  }
  inputFile >> std::ws;
  if (inputFile.eof())
  {
    std::cerr << "File is empty\n";
    return 2;
  }
  if (!(inputFile >> rows >> cols))
  {
    std::cerr << "Failed to read rows or cols from the file\n";
    inputFile.close();
    return 2;
  }
  dynamicArray = new int* [rows];
  for (int i = 0; i < rows; ++i)
  {
    dynamicArray[i] = new int[cols];
    for (int j = 0; j < cols; ++j)
    {
      if (!(inputFile >> dynamicArray[i][j]))
      {
        std::cerr << "Invalid data\n";
        inputFile.close();
        for (int k = 0; k < rows; ++k)
        {
          delete[] dynamicArray[k];
        }
        delete[] dynamicArray;
        return 2;
      }
    }
  }
  int temp;
  if (inputFile >> temp)
  {
    std::cerr << "Too many elements in the matrix\n";
    inputFile.close();
    return 2;
  }
  inputFile.close();
  return 0;
}
int gorbunova::writeResultToFile(const char* fileName, int result)
{
    std::ofstream outputFile(fileName);
    if (outputFile.is_open())
    {
        outputFile << (result == 1 ? "true\n" : "false\n");
        outputFile.close();
    }
    else
    {
        std::cerr << "Unable to open output file " << fileName << std::endl;
        return 2;
    }
    return 0;
}

