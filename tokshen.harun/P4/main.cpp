#include "Functions.hpp"
#include <iostream>
using namespace toksen;
int main(int args, const char* argv[])
{
  try
  {
    int number = toksen::fillArguments(args, argv);
    Matrix matrix1;
    matrix1.line = readInput();
    matrix1.column = readInput();
    if (number == 1) {
    int static_array[10000] = {0};
    matrix1.values = static_array;
    matrix1.fillArray();
    matrix1.writeAnswer();
    }
    else if (number == 2) {
    int *dynamic_array = new int[matrix1.line * matrix1.column];
    matrix1.values = dynamic_array;
      try
      {
      matrix1.fillArray();
      matrix1.writeAnswer();
      delete[] dynamic_array;
      }
      catch (std::logic_error const &e) {
      std::cerr << e.what();
      delete[] dynamic_array;
      return 2;
      }
    }
  }

  catch (std::invalid_argument& e) {
  std::cerr << e.what();
  return 1;
  }
  catch (std::logic_error& e) {
  std::cerr << e.what();
  return 2;
  }
}
