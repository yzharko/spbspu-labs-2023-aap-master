#include <iostream>
#include "classes/shapes/shapes.hpp"
#include "utils/base-types.hpp"
#include "utils/base-types.cpp"
#include "utils/base-fucntiuons.hpp"
#include "utils/base-fucntiuons.cpp"

int main()
{
  std::cout << "Hi"; // Lavran TODO: Удалить (Талисман :>)


  size_t shapeCount = 0;
  likhachev::Shape *shapes[1000];
  double shapeParams[10] {0};

  std::string shapeName = "";
  while (std::cin >> shapeName) {
    if (shapeName == "PARALLELOGRAM" || shapeName == "RING" || shapeName == "RECTANGLE") {
      // Lavran TODO: Присутствуют повтоерия. Попробовать заменить.
      int paramsCount = 0;
      if (shapeName == "PARALLELOGRAM") {
        paramsCount = 6;
        for (int i = 0; i < paramsCount; i++) {
          std::cin >> shapeParams[i];
        }
        shapes[shapeCount] = new likhachev::Parallelogram({shapeParams[0], shapeParams[1]},
                                                          {shapeParams[2], shapeParams[3]},
                                                          {shapeParams[4], shapeParams[5]});
      }

      if (shapeName == "RING") {
        paramsCount = 4;
        for (int i = 0; i < paramsCount; i++) {
          std::cin >> shapeParams[i];
        }
        shapes[shapeCount] = new likhachev::Ring({shapeParams[0], shapeParams[1]},
                                                  shapeParams[2], shapeParams[3]);
      }

      if (shapeName == "RECTANGLE") {
        paramsCount = 4;
        for (int i = 0; i < paramsCount; i++) {
          std::cin >> shapeParams[i];
        }
        shapes[shapeCount] = new likhachev::Rectangle({shapeParams[0], shapeParams[1]},
                                                      {shapeParams[2], shapeParams[3]});\
      }
      shapeCount++;
    }
  }

  if (shapeCount) {
    std::cout << shapes[0]->getArea();
  }
  return 1;
}
