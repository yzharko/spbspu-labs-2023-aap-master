#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

class Shape
{
public:
    virtual double getArea() const = 0; // вычисление площади
    virtual malanin::rectangle_t getFrameRect() const = 0; // получение ограничивающего прямоугольника для фигуры
    virtual void move(const malanin::point_t & newPos) = 0; // перемещение  в конкретную точку
    virtual void move(double dx, double dy) = 0; //  в виде смещений по осям абсцисс и ординат(координат)
    virtual void scale(double scaleFactor) = 0; // изотропное масштабирование относительно центра с коэф.
};
#endif