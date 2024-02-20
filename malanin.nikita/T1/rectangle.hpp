#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp" 

class Rectangle : public Shape
{
public:
    Rectangle(const malanin::point_t& pos, double width, double height);

    double getArea() const override; // вычисление площади
    malanin::rectangle_t  getFrameRect() const; // получение ограничивающего прямоугольника
    void move(const malanin::point_t& newPos); // перемещение в конкретную точку
    void move(double dx, double dy) override; // перемещение смещениями по осям
    void scale(double scaleFactor) override; // масштабирование относительно центра

private:
    malanin::point_t pos_; // позиция центра прямоугольника
    double width_; // ширина прямоугольника
    double height_; // высота прямоугольника
};

#endif // RECTANGLE_HPP