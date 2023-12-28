#include "rectangle.hpp"
#include <iostream>
#include <cstring>

mihalchenko::Restangle::Restangle() : x1_(10.0) , y1_(10.0), x2_(0.0), y2_(0.0) {}

mihalchenko::Restangle::Restangle(float x1, float y1, float x2, float y2) : x1_(x1), y1_(y1), x2_(x2), y2_(y2) {};

mihalchenko::Restangle::~Restangle()
{

}
//virtual
float mihalchenko::Restangle::getArea(float x1, float y1, float x2, float y2) //вычисление площади
{
  //RECTANGLE 1.0 1.0 3.0 4.0
  float a = abs(x2 - x1);
  float b = abs(y2 - y1);
  return a * b;
}
//virtual float mihalchenko::Restangle::getFrameRect(); /*получение ограничивающего прямоугольника для фигуры (см. типы из предыдуще-
                 //го пункта), стороны ограничивающего прямоугольника всегда параллельны осям*/
//{

//}
//virtual float mihalchenko::Restangle::move(); /*перемещение центра фигуры, 2 варианта: в конкретную точку и в виде смещений по осям
                 //абсцисс и ординат*/
//{

//}
//virtual float mihalchenko::Restangle::scale(); //изотропное масштабирование фигуры относительно её центра с указанным коэффициентом
//{

//}
