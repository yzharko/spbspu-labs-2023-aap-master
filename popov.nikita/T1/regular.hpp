#ifndef REGULAR_HPP
#define REGULAR_HPP
#include "shape.hpp"

namespace popov
{
  class Regular : public Shape
  {
    private:
    point_t first_pos_;
    point_t second_pos_;
    point_t third_pos_;
    public:
    Regular(float x1, float y1, float x2, float y2,float x3, float y3);
    float getDistance(const point_t& other);
    float getArea();
    rectangle_t getFrameRect()
    void move(float x, float y);
    void scale(float n);
  }
}

#endif
