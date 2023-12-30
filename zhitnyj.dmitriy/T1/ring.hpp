#ifndef RING_HPP
#define RING_HPP

#include "shape.hpp"

class Ring : public Shape
{
public:
    Ring(const point_t& center, float outerRadius, float innerRadius);
    Ring* clone() const override;
    float getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& newPos) override;
    void move(float dx, float dy) override;
    void scale(float scaleFactor) override;

private:
    point_t center_;
    float outerRadius_;
    float innerRadius_;
};

#endif
