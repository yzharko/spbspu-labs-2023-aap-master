#ifndef FUNCINOUT_HPP
#define FUNCINOUT_HPP
#include <string>
#include "shape.hpp"
#include "poligon.hpp"

namespace mihalchenko
{
  bool isPoligon(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);

  Shape **resizeArrayOfShapes(Shape **arrayGeomShapes, size_t sizeOfArrShapes);

  void delDinStorage(Shape **arrayGeomShapes, size_t shapeCounter);

  size_t recordingArrayOfShapes(Shape **arrayGeomShapes, size_t shapeCounter, size_t markerGeomShape);

  size_t processingAndOut(Shape **arrayGeomShapes, size_t shapeCounter);

  point_t *dinResize(point_t *points, size_t counterOfPoints, size_t sizeArrayOfPoints, const size_t addArrayOfPoints);

  void sortingShell(double *arr[], size_t num);

  void savePoligon(size_t count, point_t *points);
}
#endif
