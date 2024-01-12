#include <iostream>
#include <cstring>
#include "base-types.hpp"
#include "base-types-ff.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "complexquad.hpp"
#include "compositeShape.hpp"

using namespace anikanov;

bool isNumber(const char *);

void checkFigure(char *, CompositeShape &);

void clearWord(char *, size_t &length, size_t &bufferSize);

char * inputWord(char *, size_t &length, size_t &bufferSize);

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

bool isNumber(const char *str)
{
  char *end;

  std::strtod(str, &end);
  if (*end == '\0' && end != str) {
    return true;
  }

  return false;
}

void checkFigure(char *word, CompositeShape &compositeShape){
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
  }
}

void clearWord(char *word, size_t &length, size_t &bufferSize){
  for (size_t i = 0; i < bufferSize; ++i) {
    word[i] = '\0';
    length = 0;
  }
}

char * inputWord(char *word, size_t &length, size_t &bufferSize){
  char ch;
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
  return word;
}
