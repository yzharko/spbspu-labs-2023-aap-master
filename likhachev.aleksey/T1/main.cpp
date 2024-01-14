#include <iostream>
#include <iomanip>
#include "classes/shapes/shapes.hpp"
#include "utils/utils.hpp"

int main()
{
  size_t shapeCount = 0;
  likhachev::Shape *shapes[1000];
  bool haveErrors = false;

  std::string shapeName = "";
  while (std::cin >> shapeName && shapeName != "SCALE") {
    if (shapeName == "PARALLELOGRAM" || shapeName == "RING" || shapeName == "RECTANGLE") {
      // Lavran TODO: Присутствуют повтоерия. Попробовать заменить.
      double *shapeParams = nullptr;
      int paramsCount = 0;
      try {
        if (shapeName == "PARALLELOGRAM") {
          paramsCount = 6;
          shapeParams = new double[paramsCount];
          for (int i = 0; i < paramsCount; i++) {
            std::cin >> shapeParams[i];
          }
          shapes[shapeCount] = new likhachev::Parallelogram({shapeParams[0], shapeParams[1]},
                                                            {shapeParams[2], shapeParams[3]},
                                                            {shapeParams[4], shapeParams[5]});
        }

        if (shapeName == "RING") {
          paramsCount = 4;
          shapeParams = new double[paramsCount];
          for (int i = 0; i < paramsCount; i++) {
            std::cin >> shapeParams[i];
          }
          shapes[shapeCount] = new likhachev::Ring({shapeParams[0], shapeParams[1]},
                                                    shapeParams[2], shapeParams[3]);
        }

        if (shapeName == "RECTANGLE") {
          paramsCount = 4;
          shapeParams = new double[paramsCount];
          for (int i = 0; i < paramsCount; i++) {
            std::cin >> shapeParams[i];
          }
          shapes[shapeCount] = new likhachev::Rectangle({shapeParams[0], shapeParams[1]},
                                                        {shapeParams[2], shapeParams[3]});
        }
        shapeCount++;
      } catch(std::logic_error const& e) {
        haveErrors = true;
      }
      delete[] shapeParams;
    }
  }

  if (shapeCount == 0) {
    std::cerr << "There is nothing to scale" << "\n";
    for (size_t i = 0; i < shapeCount; i++) {
      delete shapes[i];
    }
    return 1;
  }

  if (shapeName != "SCALE") {
    std::cerr << "The scale command is missing" << "\n";
    for (size_t i = 0; i < shapeCount; i++) {
      delete shapes[i];
    }
    return 1;
  }

  std::cout << std::fixed << std::setprecision(1);
  likhachev::coutShapesData(shapes, shapeCount);
  std::cout << "\n";

  likhachev::point_t scalePoint(0, 0);
  double scaleMulti = 0;
  std::cin >> scalePoint.x >> scalePoint.y >> scaleMulti;

  if (scaleMulti <= 0) {
    std::cerr << "The scale parameter must be positive" << "\n";
    for (size_t i = 0; i < shapeCount; i++) {
      delete shapes[i];
    }
    return 1;
  }

  for (size_t i = 0; i < shapeCount; i++) {
    likhachev::point_t newPos((shapes[i]->getPos().x - scalePoint.x) * scaleMulti + scalePoint.x,
                              (shapes[i]->getPos().y - scalePoint.y) * scaleMulti + scalePoint.y);
    shapes[i]->scale(scaleMulti);
    shapes[i]->move(newPos);
  }

  likhachev::coutShapesData(shapes, shapeCount);
  std::cout << "\n";

  for (size_t i = 0; i < shapeCount; i++) {
    delete shapes[i];
  }

  if (haveErrors) {
    std::cerr << "There is an error in the description of the supported shapes";
  }

  return 0;
}
