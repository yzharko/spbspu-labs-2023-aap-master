#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace khomichenko
{
  class Diamond : public Shape
  {
    public:
      Diamond (point_t first, point_t second, point_t third);
      double getArea();
      rectangle_t getFrameRect();
      void move (point_t dPos);
      void move (double dX, double dY);
      void scale (double k);

      point_t first;
      point_t second;
      point_t third;
  };
}

#endif
