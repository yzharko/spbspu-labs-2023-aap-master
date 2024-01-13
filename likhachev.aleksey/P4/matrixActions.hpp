#ifndef MATRIX_ACTIONS_HPP
#define MATRIX_ACTIONS_HPP
#include <fstream>

namespace likhachev
{
  void inputMatrixFromFile(int sizeX, int sizeY, std::ifstream& inStream, int* values);
  void outputMatrixToFile(int sizeX, int sizeY, std::ofstream& outStream, int* values);

  void changeMatrixWithSpiral(int sizeX, int sizeY, int* values);
  int countNonRepeatColumns(int sizeX, int sizeY, int* values);
};
#endif
