#ifndef SQUARE_HPP
#define SQUARE_HPP
#include <cstring>
#include "shape.hpp"

namespace mihalchenko
{
  class Square //: public Shape  // класс прямоугольника
  {
  public:
    float x_ = 7;
    float y_ = 7;
    float width_ = 10;

    Square();
    Square(float x, float y, float width);
    ~Square();
    float getArea(float x, float y, float width); //вычисление площади
    //virtual float getFrameRect(); /*получение ограничивающего прямоугольника для фигуры (см. типы из предыдуще-
                 //го пункта), стороны ограничивающего прямоугольника всегда параллельны осям*/
    //virtual float move(); /*перемещение центра фигуры, 2 варианта: в конкретную точку и в виде смещений по осям
                 //абсцисс и ординат*/
    //virtual float scale(); //изотропное масштабирование фигуры относительно её центра с указанным коэффициентом
  };
}
#endif
