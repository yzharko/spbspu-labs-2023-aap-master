#include <iostream>
#include <cstring>
#include "base-types.hpp"
#include "base-types-ff.hpp"
#include "square.hpp"
#include "rectangle.hpp"
#include "complexquad.hpp"
#include "compositeShape.hpp"

using namespace anikanov;

bool isNumber(const char *str);

int main()
{
  CompositeShape compositeShape;

  size_t bufferSize = 10;
  char *word = new char[bufferSize];
  size_t length = 0;
  do {
    try {
      char ch;
      for (size_t i = 0; i < bufferSize; ++i) {
        word[i] = '\0';
        length = 0;
      }
      while (std::cin.get(ch)) {
        if (ch == '\n' || ch == ' ' || ch == '\0') {
          break;
        }
        if (length == bufferSize - 1) {
          bufferSize *= 2;
          char *newBuffer = new char[bufferSize];
          std::copy(word, word + length, newBuffer);
          delete[] word;
          word = newBuffer;
        }

        word[length++] = ch;
      }
      word[length] = '\0';
      if (std::cin.eof()) {
        std::cerr << "EOF\n";
        delete[] word;
        return 1;
      }
      if (std::strcmp(word, "") == 0) {
        continue;
      }
      if (isNumber(word)) {
        continue;
      }
      if (std::strcmp(word, "RECTANGLE") == 0) {
        auto *rec = new Rectangle();
        try{
          std::cin >> *rec;
          compositeShape.add(rec);
        } catch (const std::overflow_error &ex){
          delete rec;
          throw ex;
        }
      } else if (std::strcmp(word, "SQUARE") == 0) {
        auto *square = new Square();
        try{
        std::cin >> *square;
        compositeShape.add(square);
        } catch (const std::overflow_error &ex){
          delete square;
          throw ex;
        }
      } else if (std::strcmp(word, "COMPLEXQUAD") == 0) {
        auto *complexquad = new Complexquad();
        try{
        std::cin >> *complexquad;
        compositeShape.add(complexquad);
        } catch (const std::overflow_error &ex){
          delete complexquad;
          throw ex;
        }
      } else {
        continue;
      }
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

bool isNumber(const char *str)
{
  char *end;

  std::strtod(str, &end);
  if (*end == '\0' && end != str) {
    return true;
  }

  return false;
}
