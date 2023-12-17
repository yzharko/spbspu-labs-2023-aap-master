#ifndef SHAPE_HPP
#define SHAPE_HPP

namespace mihalchenko
{
  class Shape
  {
  public:
    /*float x1 = 0.0;
    float x2 = 0.0;
    float x3 = 0.0;
    float y1 = 0.0;
    float y2 = 0.0;
    float y3 = 0.0;
    float Radius1 = 0.0;
    float Radius2 = 0.0;
    */
    Shape();
    ~Shape();
    virtual float getArea(); //вычисление площади
    virtual float getFrameRect(); /*получение ограничивающего прямоугольника для фигуры (см. типы из предыдуще-
                 го пункта), стороны ограничивающего прямоугольника всегда параллельны осям*/
    virtual float move(); /*перемещение центра фигуры, 2 варианта: в конкретную точку и в виде смещений по осям
                 абсцисс и ординат*/
    virtual float scale(); //изотропное масштабирование фигуры относительно её центра с указанным коэффициентом
  };
}
#endif
