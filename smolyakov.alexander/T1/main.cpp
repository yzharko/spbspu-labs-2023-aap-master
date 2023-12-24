#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "compositeShape.hpp"

int main()
{
  using namespace smolyakov;

  Shape* shapes[2];
  Rectangle rect = Rectangle(point_t{0, 0}, point_t{10, 10});
  Circle circ = Circle(point_t{20, 20}, 5);
  shapes[0] = &rect;
  shapes[1] = &circ;

  std::cout << shapes[0]->getArea() << '\n';
  std::cout << shapes[1]->getArea() << '\n';

  CompositeShape composite = CompositeShape(10);
  composite.addShape(rect);
  composite.addShape(rect);
  composite.addShape(circ);

  std::cout << "Composite area with double rectangle: ";
  std::cout << composite.getArea() << '\n';

  composite.removeShape(rect);
  std::cout << "Composite area without double rectangle: ";
  std::cout << composite.getArea() << '\n';

  return 0;
}
