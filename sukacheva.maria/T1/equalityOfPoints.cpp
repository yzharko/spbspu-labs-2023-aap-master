#include "equalityOfPoints.hpp"

bool sukacheva::arePointsEqual(const sukacheva::point_t point1, const sukacheva::point_t point2) {
  return (point1.x == point2.x) && (point1.y == point2.y);
}
