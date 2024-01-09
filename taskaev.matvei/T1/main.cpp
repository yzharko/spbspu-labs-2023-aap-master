#include <iostream>
#include "ellipse.hpp"
#include "Shape.hpp"
#include "concave.hpp"
#include "rectangle.hpp"
#include "baseTypes.hpp"
using namespace taskaev;

int main()
{
  Shape * rectangle = new Rectangle({ 1.0, 1.0 }, { 3.0, 4.0 });
  rectangle->getArea();
  rectangle->getFrameRect();
  rectangle->move({ 0.0, 0.0 });
  rectangle->move(2.0, 3.0);
  rectangle->scale(2.0);
  delete[] rectangle;

  Shape * ellipse = new Ellipse({ 0.0, 0.0 },  10.0, 20.0 );
  ellipse->getArea();
  ellipse->getFrameRect();
  ellipse->move({ 0.0, 0.0 });
  ellipse->move(2.0, 3.0);
  ellipse->scale(2.0);
  delete[] ellipse;

  Shape * concave = new Concave({ 0.0, 5.0 }, { 0.0, 0.0 }, { 10.0, -1.0 }, { 1.0, 1.0 });
  concave->getArea();
  concave->getFrameRect();
  concave->move({ 0.0, 0.0 });
  concave->move(2.0, 3.0);
  concave->scale(2.0);
  delete[] concave;
  return 0;
}
