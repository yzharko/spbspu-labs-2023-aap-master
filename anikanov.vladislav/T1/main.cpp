#include <iostream>
#include <cstring>
#include "main-ext.hpp"
#include "base-types.hpp"
#include "base-types-ff.hpp"

using namespace anikanov;

int main()
{
  CompositeShape compositeShape;

  size_t bufferSize = 10;
  size_t length = 0;
  char *word = new char[bufferSize];

  do {
    try {
      clearWord(word, length, bufferSize);
      word = inputWord(word, length, bufferSize);
      if (std::cin.eof()) {
        std::cerr << "EOF\n";
        delete[] word;
        return 1;
      }
      if (std::strcmp(word, "") == 0 || isNumber(word)) {
        continue;
      }
      checkFigure(word, compositeShape);
    } catch (const std::overflow_error &ex) {
      std::cerr << ex.what() << "\n";
    } catch (const std::exception &ex) {
      std::cerr << ex.what() << "\n";
      delete[] word;
      return 1;
    }
  } while (std::strcmp(word, "SCALE") != 0);
  delete[] word;

  point_t center;
  std::cin >> center;
  float k;
  std::cin >> k;
  try {
    compositeShape.scale(std::cout, center, k);
  } catch (const std::exception &ex) {
    std::cerr << ex.what();
    return 1;
  }
  return 0;
}
