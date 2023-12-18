#include <iostream>
#include <fstream>
#include <string>
#include "function.hpp"

int main(int argc, char* argv[]) {
  if (argc != 4) {
    std::cerr << "Incorrect number of arguments." << std::endl;
    return 1;
  }

  int num;
  try {
    num = std::stoi(argv[1]);
  }
  catch (std::exception&) {
    std::cerr << "First argument is not a number." << std::endl;
    return 1;
  }

  if (num != 1 && num != 2) {
    std::cerr << "First argument is out of range." << std::endl;
    return 1;
  }

  std::ifstream inputFile(argv[2]);
  if (!inputFile) {
    std::cerr << "Failed to open input file." << std::endl;
    return 2;
  }

  std::ofstream outputFile(argv[3]);
  if (!outputFile) {
    std::cerr << "Failed to open output file." << std::endl;
    inputFile.close();
    return 2;
  }

  try {
    if (num == 1) {
      processFixedArray(inputFile, outputFile);
    }
    else {
      processDynamicArray(inputFile, outputFile);
    }
  }
  catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    inputFile.close();
    outputFile.close();
    return 2;
  }

  inputFile.close();
  outputFile.close();
  return 0;
}
