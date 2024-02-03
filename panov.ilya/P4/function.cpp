#include "function.hpp"
#include <iostream>
#include <fstream>

void processFixedArray(std::ifstream& inputFile, std::ofstream& outputFile) {
  int rows, columns;
  inputFile >> rows >> columns;

  if (inputFile.fail()) {
    throw std::runtime_error("Error reading input file.");
  }

  if (rows < 0 || columns < 0) {
    throw std::runtime_error("Invalid dimensions in input file.");
  }

  if (rows * columns > 10000) {
    throw std::runtime_error("Number of elements exceeds limit.");
  }

  std::vector<std::vector<int>> array(rows, std::vector<int>(columns));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      inputFile >> array[i][j];
      if (inputFile.fail()) {
        throw std::runtime_error("Error reading input file.");
      }
    }
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      outputFile << array[i][j] << " ";
    }
    outputFile << std::endl;
  }
}

void processDynamicArray(std::ifstream& inputFile, std::ofstream& outputFile) {
  int rows, columns;
  inputFile >> rows >> columns;

  if (inputFile.fail()) {
    throw std::runtime_error("Error reading input file.");
  }

  if (rows < 0 || columns < 0) {
    throw std::runtime_error("Invalid dimensions in input file.");
  }

  std::vector<std::vector<int>> array(rows, std::vector<int>(columns));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      inputFile >> array[i][j];
      if (inputFile.fail()) {
        throw std::runtime_error("Error reading input file.");
      }
    }
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      outputFile << array[i][j] << " ";
    }
    outputFile << std::endl;
  }
}
