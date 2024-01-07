#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace popov
{
  class Rectangle : public Shape
  {
    public:
    Rectangle(float x1, float y1, float x2, float y2);
    float getArea() override;
    rectangle_t getFrameRect() override;
    void move(point_t n) override;
    void move(float x, float y) override;
    void scale(float n) override;
    point_t pointLD;
    point_t pointRU;
    float width;
    float hight;
    point_t pos;
  };
}
#endif
