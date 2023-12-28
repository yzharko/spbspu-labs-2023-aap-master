#ifndef RESTANGLE_HPP
#define RESTANGLE_HPP
#include <cstring>
#include "shape.hpp"

namespace mihalchenko
{
  class Restangle //: public Shape  // класс прямоугольника
  {
  public:
    float x1_ = 7;
    float y1_ = 7;
    float x2_ = 10;
    float y2_ = 20;

    Restangle();
    Restangle(float x1, float y1, float x2, float y2);
    ~Restangle();

    float getArea(float x1, float y1, float x2, float y2); //вычисление площади
    //virtual float getFrameRect(); /*получение ограничивающего прямоугольника для фигуры (см. типы из предыдуще-
                 //го пункта), стороны ограничивающего прямоугольника всегда параллельны осям*/
    //virtual float move(); /*перемещение центра фигуры, 2 варианта: в конкретную точку и в виде смещений по осям
                 //абсцисс и ординат*/
    //virtual float scale(); //изотропное масштабирование фигуры относительно её центра с указанным коэффициентом
  };
}
#endif
