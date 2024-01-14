#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "shape.hpp"

namespace zheleznyakov
{
  class Diamond : public zheleznyakov::Shape
  {
  public:
    Diamond(point_t p1, point_t p2, point_t p3);
    double getArea();
    zheleznyakov::rectangle_t getFrameRect();
    void move(zheleznyakov::point_t point);
    void move(double x, double y);
    void scale(double k);
  private:
    point_t points_[3];
  };
  bool checkIsRighrTriangle(point_t p1, point_t p2, point_t p3);
}
#endif
