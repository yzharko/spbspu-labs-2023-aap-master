#ifndef POLYGON_HPP
#define POLYGON_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace khomichenko
{
  class Polygon : public Shape
  {
    public:
      //Polygon ();
      double getArea();
      rectangle_t getFrameRect();
      void move (point_t dPos);
      void move (double dX, double dY);
      void scale (point_t pos, double k);
    private:
      point_t first;
      point_t second;
      point_t third;
  };
}

#endif
