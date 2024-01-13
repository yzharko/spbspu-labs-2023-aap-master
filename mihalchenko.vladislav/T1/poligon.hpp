#ifndef POLIGON_HPP
#define POLIGON_HPP
#include "shape.hpp"
#include <cstddef>

namespace mihalchenko
{
  class Poligon : public Shape
  {
  public:
    Poligon(size_t count, point_t *points);
    ~Poligon();
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    // void move(const point_t point) override;
    void move(const mihalchenko::point_t &point);
    void move(const double dx, const double dy) override;
    void scale(double koef) override;

  private:
    size_t counterOfPoints_ = 0;
    point_t *arrayOfPoints_ = nullptr;
    rectangle_t rectangle_;
  };
}
#endif
