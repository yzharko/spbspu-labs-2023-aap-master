#ifndef POLIGON_HPP
#define POLIGON_HPP
#include "shape.hpp"

namespace mihalchenko
{
  class Poligon : public Shape
  {
  public:
    Poligon();
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &point) override;
    void move(const double deltaX, const double deltaY) override;
    void scale(double scaleKoef) override;

  private:
    point_t pos1_;
    point_t pos2_;
    point_t pos3_;
    point_t pos4_;
    rectangle_t rectangle_;
  };
}
#endif
