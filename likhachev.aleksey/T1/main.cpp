#include <iostream>
#include <iomanip>
#include "classes/shapes/shapes.hpp"
#include "utils/utils.hpp"

int main()
{
  size_t shapeCount = 0;
  likhachev::Shape *shapes[1000];

  std::string shapeName = "";
  while (std::cin >> shapeName && shapeName != "SCALE") {
     double *shapeParams = nullptr;
    if (shapeName == "PARALLELOGRAM" || shapeName == "RING" || shapeName == "RECTANGLE") {
      // Lavran TODO: Присутствуют повтоерия. Попробовать заменить.
      int paramsCount = 0;
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
                                                      {shapeParams[2], shapeParams[3]});\
      }
      delete[] shapeParams;
      shapeCount++;
    }
  }

  std::cout << std::fixed << std::setprecision(1);
  likhachev::coutShapesData(shapes, shapeCount);
  std::cout << "\n";

  likhachev::Point_t scalePoint(0, 0);
  double scaleMulti = 0;
  std::cin >> scalePoint.x >> scalePoint.y >> scaleMulti;
  for (size_t i = 0; i < shapeCount; i++) {
    likhachev::Point_t newPos((shapes[i]->getPos().x - scalePoint.x) * scaleMulti + scalePoint.x,
                              (shapes[i]->getPos().y - scalePoint.y) * scaleMulti + scalePoint.y);
    shapes[i]->scale(scaleMulti);
    shapes[i]->move(newPos);
  }

  likhachev::coutShapesData(shapes, shapeCount);

  for (size_t i = 0; i < shapeCount; i++) {
    delete shapes[i];
  }

  return 0;
}
