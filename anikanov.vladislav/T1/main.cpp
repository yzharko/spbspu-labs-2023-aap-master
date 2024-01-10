#include <iostream>
#include <cstring>
#include "base-types.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "complexquad.hpp"
#include "compositeShape.hpp"

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
          // Расширяем буфер
          bufferSize *= 2;
          char *newBuffer = new char[bufferSize];
          std::copy(word, word + length, newBuffer);
          delete[] word;
          word = newBuffer;
        }

        word[length++] = ch;
      }
      word[length] = '\0';
      if (std::strcmp(word, "") == 0){
        continue;
      }
      if (isNumber(word)){
        continue;
      }
      if (std::strcmp(word, "RECTANGLE") == 0) {
        auto *rec = new Rectangle();
        std::cin >> *rec;
        compositeShape.add(rec);
      } else if (std::strcmp(word, "SQUARE") == 0) {
        auto *square = new Square();
        std::cin >> *square;
        compositeShape.add(square);
      } else if (std::strcmp(word, "COMPLEXQUAD") == 0) {
        auto *complexquad = new Complexquad();
        std::cin >> *complexquad;
        compositeShape.add(complexquad);
      } else  {
        continue;
      }
      if (std::cin.eof()){
        std::cerr << "EOF\n";
        delete[] word;
        return 1;
      }
    } catch (const std::overflow_error &ex) {
      std::cerr << ex.what() << "\n";
    } catch (const std::exception &ex) {
      std::cerr << ex.what() << "\n";
      delete[] word;
      return 1;
    }
  } while (std::strcmp(word, "SCALE") != 0);
  PointT center;
  std::cin >> center;
  float k;
  std::cin >> k;
  compositeShape.scale(std::cout, center, k);
  delete[] word;
}

bool isNumber(const char *str)
{
  char* end;

  std::strtod(str, &end);
  if (*end == '\0' && end != str) {
    return true;
  }

  return false;
}
