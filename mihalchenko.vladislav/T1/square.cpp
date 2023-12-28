#include "square.hpp"
#include <cstring>
#include "shape.hpp"

mihalchenko::Square::Square()
{
  //std::cout << "Square TEST" << std::endl;
}

mihalchenko::Square::~Square()
{

}

float mihalchenko::Square::getArea(float x, float y, float width)
{
  //вычисление площади
  return width * width;
}
  //virtual float getFrameRect(); /*получение ограничивающего прямоугольника для фигуры (см. типы из предыдуще-
               //го пункта), стороны ограничивающего прямоугольника всегда параллельны осям*/
  //virtual float move(); /*перемещение центра фигуры, 2 варианта: в конкретную точку и в виде смещений по осям
               //абсцисс и ординат*/
  //virtual float scale(); //изотропное масштабирование фигуры относительно её центра с указанным коэффициентом
//};
