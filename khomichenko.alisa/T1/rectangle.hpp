#ifndef RECT_HPP
#define RECT_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace khomichenko
{
  class Rectangle : public Shape
  {
    public:
      Rectangle (point_t leftBottom, point_t rightTop);
      double getArea();
      rectangle_t getFrameRect();
      void move (point_t dPos);
      void move (double dX, double dY);
      void scale (point_t pos, double k);
    private:
      point_t leftBottom;
      point_t rightTop;
  };
}

#endif
