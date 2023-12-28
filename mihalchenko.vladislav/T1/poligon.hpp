#ifndef POLIGON_HPP
#define POLIGON_HPP
#include <cstring>
#include "shape.hpp"

namespace mihalchenko
{
  class Poligon //: public Shape  // класс прямоугольника
  {
  public:
    float x1_ = 7;
    float y1_ = 7;
    float x2_ = 10;
    float y2_ = 20;
    float x3_ = 10;
    float y3_ = 20;
    float width_ = 10;
    float height_ = 20;

    Poligon();
    Poligon(float x1, float y1, float x2, float y2, float x3, float y3);
    ~Poligon();
    float getArea(float width, float height); //вычисление площади
    //virtual float getFrameRect(); /*получение ограничивающего прямоугольника для фигуры (см. типы из предыдуще-
                 //го пункта), стороны ограничивающего прямоугольника всегда параллельны осям*/
    //virtual float move(); /*перемещение центра фигуры, 2 варианта: в конкретную точку и в виде смещений по осям
                 //абсцисс и ординат*/
    //virtual float scale(); //изотропное масштабирование фигуры относительно её центра с указанным коэффициентом
  };
}
#endif
