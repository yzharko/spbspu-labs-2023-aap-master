#include <iostream>
#include <fstream>
#include <cstring>
#include "functions.hpp"

int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    std::cerr << "Error: wrong args count.\n";
    return 1;
  }
  int task = 0;
  try
  {
    char * arg = argv[1];
    for (size_t i = 0; i < std::strlen(arg); i++)
    {
      if (!(std::isdigit(arg[i])))
      {
        throw std::invalid_argument("Error: The task number is not an integer.\n");
      }
    }
    task = std::stoll(arg);
  }
  catch (const std::invalid_argument &e)
  {
    std::cerr << "Error: Cannot read task ID: Invalid argument.\n";
    return 1;
  }
  catch (const std::istream::failure &e)
  {
    std::cerr << "Error: Cannot read task ID: input error.\n";
    return 1;
  }
  if (task != 1 && task != 2)
  {
    std::cerr << "Error: I can't do that - this task ID is invalid.\n";
    return 1;
  }
  std::ifstream inputStream;
  inputStream.open(argv[2]);
  std::ofstream outputStream;
  outputStream.open(argv[3]);
  int columns = 0;
  int rows = 0;
  inputStream >> columns;
  inputStream >> rows;
  if (!inputStream)
  {
    std::cerr << "Error: Cannot read input.\n";
    return 2;
  }
  int result = 0;
  int * array = {};
  try
  {
    array = task == 2 ? new int[columns * rows] : new int[10000];
    zheleznyakov::readMatrix(inputStream, array, columns, rows);
    result = zheleznyakov::findMaxRowInMatrix(array, columns, rows);
    delete[] array;
  }
  catch (const std::runtime_error &e)
  {
    delete[] array;
    std::cerr << e.what();
    return 2;
  }
  catch (const std::bad_alloc &e)
  {
    delete[] array;
    std::cerr << "Error: Cannot reserve memory.\n";
    return 2;
  }
  outputStream << result;
  return 0;
}
