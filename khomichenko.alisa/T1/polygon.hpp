#ifndef POLYGON_HPP
#define POLYGON_HPP
#include "base-types.hpp"
#include "shape.hpp"
#include <iostream>

namespace khomichenko
{
  class Polygon: public Shape
  {
    public:
      Polygon(size_t num, point_t * points);
      double getArea();
      rectangle_t getFrameRect();
      void move (point_t dPos);
      void move (double dX, double dY);
      void scale (double k);

     size_t num_;
     point_t * points_;

  };
}

#endif
