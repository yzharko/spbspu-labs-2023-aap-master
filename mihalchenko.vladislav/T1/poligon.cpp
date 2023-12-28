#include "poligon.hpp"
#include <cstring>
#include "shape.hpp"

mihalchenko::Poligon::Poligon()
{

}

mihalchenko::Poligon::Poligon(float x1, float y1, float x2, float y2, float x3, float y3)
{

}

mihalchenko::Poligon::~Poligon()
{

}

float mihalchenko::Poligon::getArea(float width, float height)
{
  //вычисление площади
  //virtual float getFrameRect(); /*получение ограничивающего прямоугольника для фигуры (см. типы из предыдуще-
               //го пункта), стороны ограничивающего прямоугольника всегда параллельны осям*/
  //virtual float move(); /*перемещение центра фигуры, 2 варианта: в конкретную точку и в виде смещений по осям
               //абсцисс и ординат*/
  //virtual float scale(); //изотропное масштабирование фигуры относительно её центра с указанным коэффициентом
  //return 7;
  return width * height;
}
