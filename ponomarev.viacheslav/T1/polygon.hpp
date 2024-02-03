#ifndef POLYGON_HPP
#define POLYGON_HPP
#include "shape.hpp"
#include <cstddef>
#include <stdexcept>

namespace ponomarev
{
  class Polygon: public Shape
  {
  public:
    virtual ~Polygon();
    Polygon(const size_t countPoints, point_t * points);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & newCenter);
    virtual void move(const double & offsetX, const double & offsetY);

  private:
    size_t countPoints;
    point_t * points = 0;
    virtual void scaling(const double k);
  };
}

#endif
