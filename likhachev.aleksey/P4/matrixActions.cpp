#include "matrixActions.hpp"

void likhachev::inputMatrixFromFile(int sizeX, int sizeY, std::ifstream& inStream, int* values)
{
  if (sizeX * sizeY > 10000) {
    sizeX = 100;
    sizeY = 100;
  }

  for (int i = 0; i < sizeX * sizeY; i++) {
    inStream >> *(values + i);
    if (!inStream) {
      throw std::runtime_error("Error reading the matrix from the file.\n");
    }
  }
}

void likhachev::outputMatrixToFile(int sizeX, int sizeY, std::ofstream& outStream, int* values)
{
  outStream << sizeX << " " << sizeY << " ";
  for (int i = 0; i < sizeX * sizeY; i++) {
    outStream << values[i] << " ";
    if (!outStream) {
      throw std::runtime_error("Error writing the matrix to the file.\n");
    }
  }

  outStream << "\n";
}

int likhachev::countNonRepeatColumns(int sizeX, int sizeY, int* values)
{
  int totalCount = sizeX;

  bool hasSubbed = false;
  for ( int i = 0; i < sizeX; i++) {
    hasSubbed = false;
    for (int j = 0; j < sizeY - 1; j++) {
      if (!hasSubbed && values[sizeX * j + i] == values[sizeX * (j + 1) + i]) {
        totalCount--;
        hasSubbed = true;
      }
    }
  }

  return totalCount;
}

void likhachev::changeMatrixWithSpiral(int sizeX, int sizeY, int* values)
{
  int directionX(1);
  int directionY(0);
  int positionX(-1);
  int positionY(0);
  int submatrixSizeX(sizeX);
  int submatrixSizeY(sizeY);

  int counter = 1;
  int steps = 0;
  while (submatrixSizeX > 0 && submatrixSizeY > 0) {
    if (directionX % 2) {
      steps = submatrixSizeX;
      submatrixSizeY--;
    } else {
      steps = submatrixSizeY;
      submatrixSizeX--;
    }

    for (int j = 0; j < steps; j++) {
      positionX += directionX % 2;
      positionY += directionY % 2;
      values[positionX + positionY * sizeX] += counter;
      counter++;
    }

    directionX == 2 ? directionX = -1 : directionX++;
    directionY == 2 ? directionY = -1 : directionY++;
  }
}
