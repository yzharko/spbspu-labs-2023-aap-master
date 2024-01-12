#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"
#include <cmath>
#include <algorithm>

namespace kovshikov
{
  class Triangle: public Shape
  {
  public:
    override ~Triangle() = default;
    Triangle(point_t vertexA, point_t vertexB, point_t vertexC);
    override double getArea() const;
    override rectangle_t getFrameRect() const;
    override void move(const point_t &newPos);
    override void move(double xPlus, double yPlus);
    override void scale(double multiplier);
    point_t getPos();
    void changeVertex(const double multiplier, const point_t pos, point_t &vertex);
  private:
    point_t vertexA_;
    point_t vertexB_;
    point_t vertexC_;
  };
}

#endif
