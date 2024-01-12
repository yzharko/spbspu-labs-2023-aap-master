#ifndef SHAPEPROCESSING_HPP
#define SHAPEPROCESSING_HPP
#include <string>
#include "base-types.hpp"

namespace redko
{
  bool isTypeCorrect(std::string type);
  bool isRectangleCorrect(redko::point_t * points);
  bool isParallelogramCorrect(redko::point_t * points);
  bool isConcaveCorrect(redko::point_t * points);

  redko::point_t * getRectanglePoints();
  redko::point_t * getParallelogramPoints();
  redko::point_t * getConcavePoints();
}

#endif
