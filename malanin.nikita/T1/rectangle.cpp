#include "rectangle.hpp"

Rectangle::Rectangle(const malanin::point_t& pos, double width, double height) // конструктор класса
    : pos_(pos), width_(width), height_(height)
{
}

double Rectangle::getArea() const
{
    return width_ * height_; // площадь == произведению ширины и высоты
}

malanin::rectangle_t Rectangle::getFrameRect() const
{
    malanin::rectangle_t frameRect;
    frameRect.pos = pos_;
    frameRect.width = width_;
    frameRect.height = height_;
    return frameRect; // ограничивающий прямоугольник равен самому прямоугольнику
}

void Rectangle::move(const malanin::point_t& newPos)
{
    pos_ = newPos; // перемещаем прямоугольник в новую указанную точку
}

void Rectangle::move(double dx, double dy)
{
    pos_.x += dx; // перемещаем прямоугольник на смещение по оси абсцисс(X)
    pos_.y += dy; // перемещаем прямоугольник на смещение по оси ординат(Y)
}

void Rectangle::scale(double scaleFactor)
{
    width_ *= scaleFactor; // масштабируем ширину прямоугольника
    height_ *= scaleFactor; // масштабируем высоту прямоугольника
}