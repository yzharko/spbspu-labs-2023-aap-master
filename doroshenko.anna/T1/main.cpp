#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "concave.hpp"

int main()
{
  using namespace doroshenko;
  Shape* rectangle = new Rectangle({ 1.0, 1.0 }, { 3.0, 4.0 });
  rectangle->getArea();
  rectangle_t frameR = rectangle->getFrameRect();
  rectangle->move({ 0.0, 0.0 });
  rectangle->move(2.0, 3.0);
  rectangle->scale({ 0.0, 0.0 }, 2.0);
  delete[] rectangle;

  Shape* triangle = new Triangle({ 0.0, 0.0 }, { 1.0, 1.0 }, { 0.0, 1.0 });
  triangle->getArea();
  rectangle_t frameT = triangle->getFrameRect();
  triangle->move({ 0.0, 0.0 });
  triangle->move(2.0, 3.0);
  triangle->scale({ 0.0, 0.0 }, 2.0);
  delete[] triangle;

  Shape* concave = new Concave({ 0.0, 5.0 }, { 0.0, 0.0 }, { 10.0, -1.0 }, { 1.0, 1.0 });
  concave->getArea();
  rectangle_t frameC = concave->getFrameRect();
  concave->move({ 0.0, 0.0 });
  concave->move(2.0, 3.0);
  concave->scale({ 0.0, 0.0 }, 2.0);
  delete[] concave;
  return 0;
}
