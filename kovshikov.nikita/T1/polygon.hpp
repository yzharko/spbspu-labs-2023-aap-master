#ifndef POLYGON_HPP
#define POLYGON_HPP
#include "shape.hpp"
#include <cstddef>
#include <algorithm>

namespace kovshikov
{
  class Polygon: public Shape
  {
  public:
    Polygon(size_t num, point_t * points);
    ~Polygon() override; // нужны ли еще какие то специальные методы?
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &newPos) override;
    void move(double xPlus, double yPlus) override;
    void scale(double multiplier) override;
    point_t getPos();
  private:
    size_t num_;
    point_t * points_ = nullptr;
  };
}

#endif
