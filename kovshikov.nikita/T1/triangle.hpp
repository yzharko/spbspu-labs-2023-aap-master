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
    virtual ~Triangle() = default;
    Triangle(point_t vertexA, point_t vertexB, point_t vertexC);
    override double getArea() const;
    override rectangle_t getFrameRect() const;
    virtual void move(const point_t &newPos);
    virtual void move(double xPlus, double yPlus);
    virtual void scale(double multiplier);
    point_t getPos();
    void changeVertex(const double multiplier, const point_t pos, point_t &vertex);
  private:
    point_t vertexA_;
    point_t vertexB_;
    point_t vertexC_;
  };
}

#endif
