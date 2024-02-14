#include <iostream>
#include "upplow.hpp"
#include "lat_two.hpp"
#include <cstddef>
#include <cstring>
#include <stdexcept>

int main() {

  size_t length = 2000;
  char* str1 = new char[length + 1];
  char* str2 = new char[length + 1];
  char* temp = nullptr;

  std::cout << "Enter 1st string: " << "\n";
  try {
    std::cin.getline(str1, length + 1);

    if (std::cin.fail()) {
      throw std::runtime_error("Input overflow or other error while reading first string.");
    }

    size_t inputLength = strlen(str1);

    if (inputLength > length) {
      throw std::runtime_error("Input length error");
    }

    temp = new char[inputLength + 1];

    toksen::convertToLower(str1, temp, inputLength);

    std::cout << temp << std::endl;

    std::cout << "Enter second string : " << "\n";
    std::cin.getline(str2, length + 1);

    if (std::cin.fail()) {

      std::cout << temp;
    }
    else {
      char* mergeString = toksen::mergeLatinLetters(temp, str2);
      std::cout << mergeString;
      delete[] mergeString;
    }
  }

  catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    delete[] temp;
    delete[] str1;
    delete[] str2;
    return 1;
  }

  delete[] temp;
  delete[] str1;
  delete[] str2;
  return 0;
}
