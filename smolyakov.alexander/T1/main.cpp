#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "regular.hpp"
#include "compositeShape.hpp"

int main()
{
  using namespace smolyakov;

  Regular regular = Regular(point_t{0, 0}, point_t{0, 1}, point_t{1, 1});

  Circle circle = Circle(point_t{100, 100}, 1.0);
  Rectangle rectangle = Rectangle({5, 0}, {6, 1000});

  CompositeShape compositeShape = CompositeShape(3);
  compositeShape.addShape(regular);
  compositeShape.addShape(circle);
  compositeShape.addShape(rectangle);
  std::cout << compositeShape.getFrameRect().width << '\n' << compositeShape.getFrameRect().height << '\n';
  std::cout << compositeShape.getArea() << '\n';
}
