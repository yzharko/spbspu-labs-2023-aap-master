#ifndef SHAPE_HPP
#define SHAPE_HPP

namespace khomichenko
{
  class Shape
  {
    public:
      double getArea();
      rectangle_t getFrameRect();
      void move (point_t dPos);
      void move (double dX, double dY);
      void scale (point_t pos, double k);
  };
}

#endif
