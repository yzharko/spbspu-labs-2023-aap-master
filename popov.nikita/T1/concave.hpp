#ifndef CONCAVE_HPP
#define CONCAVE_HPP
#include "shape.hpp"

namespace popov
{
  class Concave : public Shape
  {
    private:
    point_t A_:
    point_t B_:
    point_t C_;
    point_t D_;
    public:
    Concave(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
    float getArea();
    rectangle_t getFrameRect();
    void move(float x, float y);
    void scale(float n);
  };
}

#endif
