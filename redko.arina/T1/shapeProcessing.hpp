#ifndef SHAPEPROCESSING_HPP
#define SHAPEPROCESSING_HPP
#include <string>
#include "base-types.hpp"
#include "shape.hpp"

namespace redko
{
  bool isTypeCorrect(std::string type);
  bool isRectangleCorrect(point_t * points);
  bool isParallelogramCorrect(point_t * points);
  bool isConcaveCorrect(point_t * points);

  point_t * getRectanglePoints();
  point_t * getParallelogramPoints();
  point_t * getConcavePoints();

  double countAreas(redko::Shape ** shapeArr, int shapeNum);
  double * getFrameCorners(Shape ** shapeArr, int shapeNum);
  void printFrameCorners(double * frameCorners, int shapeNum);

  void deleteShapes(Shape ** shapeArr, int shapeNum);
}

#endif
