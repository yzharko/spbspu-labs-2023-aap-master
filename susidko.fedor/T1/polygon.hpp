#include "base-types.hpp"
#include "shape.hpp"
#ifndef POLYGON_HPP
#define POLYGON_HPP

class Polygon: public Shape
{
  public:
    Polygon() = delete;
    Polygon(point_t points[]):
      points_(points),
    {}
    //point_t getP1();
    //point_t getP2();
    rectangle_t getFrameRect() override;
    double getArea() override;
    //point_t getCenter();
    //void move(double, double) override;
    //void move(point_t) override;
    rectangle_t scale(double, double, double, rectangle_t) override;
  private:
    point_t points_[];
};

#endif

