#include <iostream>
#include <cstring>
#include "base-types.cpp"
#include "rectangle.cpp"
#include "square.cpp"
#include "complexquad.cpp"
#include "compositeShape.cpp"

int main()
{
  CompositeShape compositeShape;
  bool badShape = false;
  char *word = new char[10];
  do {
    try{
      std::cin >> word;
      if (std::strcmp(word, "RECTANGLE")){

      } else if (std::strcmp(word, "RECTANGLE")) {

      } else if (std::strcmp(word, "RECTANGLE")) {

      } else if (std::strcmp(word, "RECTANGLE")) {

      } else if (badShape){

      } else if (std::isdigit()){

      }
    } catch (const std::exception){

    }
  }
  delete[] word;
}
